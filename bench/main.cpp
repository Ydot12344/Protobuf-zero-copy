#include "messge.pb.h"
#include <benchmark/benchmark.h>
#include <gtest/gtest.h>
#include <gen_data.h>
#include <fstream>

template <typename T>
class TSingletone {
public:
    template<class... TArgs>
    TSingletone(TArgs... args) {
        if (val == nullptr) {
            val = new T(std::forward(args)...);
        }
    }

    T* operator*() {
        return val;
    }

    static T* val;
};

template<class T>
T* TSingletone<T>::val = nullptr;


class TEnvHolder {
public:
    TEnvHolder() {
        // Init

        opts.Seed = 12;
        opts.NumsCount = 100;
        opts.StringsCount = 100;
        opts.StringSize = 100;
        opts.FloatCount = 100;
        opts.FilesCount = 2000;
        opts.SetsOfFilesCount = 100;

        report =  NGenProto::GenReport(opts);

        std::ofstream out("out.txt"); 
        report.SerializeToOstream(&out);
    }

    NGenProto::TGenOpts opts;
    tutorial::TReport report;
};

void CheckFilesEqual(const tutorial::TFile& a, const tutorial::TFile& b) {
    ASSERT_EQ(a.name(), b.name());
    ASSERT_EQ(a.weights_size(), b.weights_size());
    ASSERT_EQ(a.hosts_size(), b.hosts_size());

    for (size_t i = 0; i < a.weights_size(); i++) {
        ASSERT_EQ(a.weights(i), b.weights(i));
    }

    for (size_t i = 0; i < a.hosts_size(); i++) {
        ASSERT_EQ(a.hosts(i), b.hosts(i));
    }
}

void CheckSetsOfFilesEqual(const tutorial::TFileSet& a, const tutorial::TFileSet& b) {
    ASSERT_EQ(a.hash(), b.hash());

    ASSERT_EQ(a.files_size(), b.files_size());

    for (size_t i = 0; i < a.files_size(); i++) {
        CheckFilesEqual(a.files(i), b.files(i));
    }
}

void Check(const std::string& resultBin) {
    const auto& env = *TSingletone<TEnvHolder>();

    tutorial::TReport expected = env->report;
    tutorial::TReport result;

    result.ParseFromString(resultBin);

    ASSERT_EQ(result.nums_size(), 0);
    ASSERT_EQ(result.strings_size(), 0);
    ASSERT_EQ(result.setsoffiles_size(), env->opts.SetsOfFilesCount / 2);

    std::vector<tutorial::TFileSet> sets;

    for (size_t i = 0; i < expected.setsoffiles_size(); i++) {
        sets.push_back(expected.setsoffiles(i));
    }

    std::sort(sets.begin(), sets.end(), 
        [](const auto& a, const auto& b) {
            return a.hash() > b.hash();
        }
    );

    for (size_t i = 0; i < result.setsoffiles_size(); i++) {
        CheckSetsOfFilesEqual(sets[i], result.setsoffiles(i));
    }
}

static void BM_ParseProtoFromFile(benchmark::State& state) {

    const auto& env = *TSingletone<TEnvHolder>();
    std::string out;
    out.reserve(170000000);

    for (auto _ : state) {
        std::ifstream in("out.txt");

        tutorial::TReport a;
        tutorial::TReport res;

        a.ParseFromIstream(&in);

        std::sort(a.mutable_setsoffiles()->begin(), a.mutable_setsoffiles()->end(), 
            [](const auto& a, const auto& b) {return a.hash() > b.hash();}
        );

        for (size_t i = 0; i < a.setsoffiles_size() / 2; i++) {
            *res.add_setsoffiles() = a.setsoffiles(i);
        }

        res.SerializeToString(&out);
    }
    
    Check(out);
}

static void BM_CopyWithoutParsing(benchmark::State& state) {

    const auto& env = *TSingletone<TEnvHolder>();
    std::string out;
    out.reserve(170000000);
    tutorial::TReport a = env->report;
    for (auto _ : state) {
        tutorial::TReport res;

        std::sort(a.mutable_setsoffiles()->begin(), a.mutable_setsoffiles()->end(), 
            [](const auto& a, const auto& b) {return a.hash() > b.hash();}
        );

        for (size_t i = 0; i < a.setsoffiles_size() / 2; i++) {
            *res.add_setsoffiles() = a.setsoffiles(i);
        }

        res.SerializeToString(&out);
    }
    
    Check(out);
}

// Register the function as a benchmark
BENCHMARK(BM_ParseProtoFromFile);
BENCHMARK(BM_CopyWithoutParsing);
BENCHMARK_MAIN();