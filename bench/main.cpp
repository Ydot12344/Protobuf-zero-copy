#include "google/protobuf/arena.h"
#include "messge.pb.h"
#include <benchmark/benchmark.h>
#include <gtest/gtest.h>
#include <gen_data.h>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

constexpr const char* const SUBSOURCE_BIN_PREFIX = "bin_proto_data/subsources/subsource";
constexpr const char* const REPORT_BIN_PATH = "bin_proto_data/report.bin";
constexpr const char* const TEST_BIN_PATH = "bin_proto_data/test.bin";

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
        // Load config

        std::ifstream stream("/home/andreizdor/hse/diplom/bench/config.json");
        json config = json::parse(stream);

        auto bigProto = config["big_proto"];
        auto smallProto = config["small_proto"];
        
        smallOpts.FromJson(smallProto);
        bigOpts.FromJson(bigProto);

        report =  NGenProto::GenReport(bigOpts);
        test = NGenProto::GenTest(bigOpts);

        SubsourceCnt = config["subsource_cnt"];
        
        for (size_t i = 0; i < SubsourceCnt; i++) {
            subsource = NGenProto::GenSubsourceResponse(smallOpts);
            std::ofstream out (SUBSOURCE_BIN_PREFIX + std::to_string(i) + ".bin");
            subsource.SerializeToOstream(&out);
        }

        SmallProtoSize = subsource.ByteSizeLong();

        BigProtoSize = test.ByteSizeLong();
        TestBinSize = BigProtoSize;
        ReportBinSize = BigProtoSize;
        SubsourceSize = SmallProtoSize;

        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Big proto size: " << std::fixed << std::setprecision(2) << 
            BigProtoSize * 1. / 1024 / 1024 << "Mb" << std::endl;
        std::cout << "Small proto size: " << std::fixed << std::setprecision(2) << 
            SmallProtoSize * 1. / 1024 / 1024 << "Mb" << std::endl;

        std::ofstream out_report(REPORT_BIN_PATH); 
        std::ofstream out_test(TEST_BIN_PATH);

        report.SerializeToOstream(&out_report);
        test.SerializeToOstream(&out_test);
    }

    size_t TestBinSize;
    size_t ReportBinSize;
    size_t SubsourceSize;

    size_t SubsourceCnt;

    NGenProto::TGenOpts smallOpts;
    NGenProto::TGenOpts bigOpts;

    NBench::TReport report;
    NBench::TTest test;
    NBench::TSubsourceResponse subsource;

private:
    size_t BigProtoSize;
    size_t SmallProtoSize;
};

void CheckFilesEqual(const NBench::TFile& a, const NBench::TFile& b) {
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

void CheckSetsOfFilesEqual(const NBench::TFileSet& a, const NBench::TFileSet& b) {
    ASSERT_EQ(a.hash(), b.hash());

    ASSERT_EQ(a.files_size(), b.files_size());

    for (size_t i = 0; i < a.files_size(); i++) {
        CheckFilesEqual(a.files(i), b.files(i));
    }
}

void CheckSubsources(const std::string& result) {
    const auto& env = *TSingletone<TEnvHolder>();
    std::vector<NBench::TSubsourceResponse> subsources(env->SubsourceCnt);

    for (size_t i = 0; i < subsources.size(); i++) {
        std::ifstream in(SUBSOURCE_BIN_PREFIX + std::to_string(i) + ".bin");
        subsources[i].ParseFromIstream(&in);
    }

    NBench::TSubsourceResponse expected;
    for (size_t i = 0; i < subsources.size(); i++) {
        for (const auto& response : subsources[i].responses()) {
            (*expected.add_responses()) = response;
        }
    }

    ASSERT_EQ(result, expected.SerializeAsString());
} 

void Check(const std::string& resultBin) {
    const auto& env = *TSingletone<TEnvHolder>();

    NBench::TReport expected = env->report;
    NBench::TReport result;

    result.ParseFromString(resultBin);

    ASSERT_EQ(result.nums_size(), 0);
    ASSERT_EQ(result.strings_size(), 0);
    ASSERT_EQ(result.setsoffiles_size(), env->bigOpts.SetsOfFilesCount / 2);

    std::vector<NBench::TFileSet> sets;

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
    out.reserve(env->ReportBinSize);

    for (auto _ : state) {
        std::ifstream in(REPORT_BIN_PATH);

        NBench::TReport a;
        NBench::TReport res;

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
    out.reserve(env->ReportBinSize);
    NBench::TReport a = env->report;
    for (auto _ : state) {
        NBench::TReport res;

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

static void BM_ParseFromString(benchmark::State& state) {

    const auto& env = *TSingletone<TEnvHolder>();
    std::string out;
    out.reserve(env->ReportBinSize);

    std::ifstream in(REPORT_BIN_PATH);
    std::string input = std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    NBench::TReport a;
    for (auto _ : state) {
        a.ParseFromString(input);
    }
    
    //Check(out);
}

static void BM_LoadEnv(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();
}

static void BM_ParseProtoFromFileWithArena(benchmark::State& state) {

    const auto& env = *TSingletone<TEnvHolder>();
    std::string out;
    out.reserve(env->ReportBinSize);
    size_t initial_size = env->ReportBinSize;
    char* initial_block = new char[initial_size];
    google::protobuf::Arena arena(initial_block, initial_size);

    for (auto _ : state) {
        std::ifstream in(REPORT_BIN_PATH);

        NBench::TReport* a;
        NBench::TReport res;

        a = google::protobuf::Arena::CreateMessage<NBench::TReport>(&arena);

        a->ParseFromIstream(&in);

        std::sort(a->mutable_setsoffiles()->begin(), a->mutable_setsoffiles()->end(), 
            [](const auto& a, const auto& b) {return a.hash() > b.hash();}
        );

        for (size_t i = 0; i < a->setsoffiles_size() / 2; i++) {
            *res.add_setsoffiles() = a->setsoffiles(i);
        }

        res.SerializeToString(&out);
    }
    
    Check(out);
}

static void BM_TestLazyFromString(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::string input, out;
    input.reserve(env->TestBinSize);
    out.reserve(env->TestBinSize);

    std::ifstream in(TEST_BIN_PATH);
    input.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    NBench::TTestLazy a;

    std::ifstream inx(TEST_BIN_PATH);

    for (auto _ : state) {
        a.ParseFromString(input);
    }
    
    a.SerializeToString(&out);

    ASSERT_EQ(out, input);
}

static void BM_TestFromString(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::string input, out;
    input.reserve(env->TestBinSize);
    out.reserve(env->TestBinSize);

    std::ifstream in(TEST_BIN_PATH);
    input.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    NBench::TTest a;

    for (auto _ : state) {
        a.ParseFromString(input);
    }

    a.SerializeToString(&out);

    ASSERT_EQ(out, input);
}

static void BM_TestTTestDefaultWork(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::string out, input;
    input.reserve(env->TestBinSize);
    out.reserve(env->TestBinSize);

    std::ifstream in(TEST_BIN_PATH);
    input.assign((std::istreambuf_iterator<char>(in) ),
                (std::istreambuf_iterator<char>()    ) );

    NBench::TTest a;

    for (auto _ : state) {
        a.ParseFromString(input);
        auto* file_set = a.mutable_wraper()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        a.SerializeToString(&out);
    }
}

static void BM_TestTTestLazyDefaultWork(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::string out, input;
    input.reserve(env->TestBinSize);
    out.reserve(env->TestBinSize);

    std::ifstream in(TEST_BIN_PATH);
    input.assign((std::istreambuf_iterator<char>(in) ),
                (std::istreambuf_iterator<char>()    ) );

    NBench::TTestLazy a;

    for (auto _ : state) {
        a.ParseFromString(input);
        auto* file_set = a.mutable_wraper()->Unpack()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        a.SerializeToString(&out);
    }

    // Check
    NBench::TTest b;
    b.ParseFromString(input);
    auto* file_set = b.mutable_wraper()->mutable_setsoffiles(0);
    file_set->set_hash(0);
    file_set->mutable_files(0)->set_name("rename_0");
    std::string out_b;
    b.SerializeToString(&out_b);

    ASSERT_EQ(out, out_b);
}

static void BM_Memcpy(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::string input;
    input.reserve(env->TestBinSize);

    std::ifstream in(TEST_BIN_PATH);
    input.assign((std::istreambuf_iterator<char>(in) ),
                (std::istreambuf_iterator<char>()    ) );

    NBench::TTestLazy a;

    char* out = new char[env->TestBinSize];

    for (auto _ : state) {
        memcpy(out, input.data(), input.size());
    }

    std::string check(out, out + input.size());
    ASSERT_EQ(check, input);

    delete[] out;
}

static void BM_ProxyConcatSubsources(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::vector<std::string> data(env->SubsourceCnt);

    for(size_t i = 0; i < data.size(); i++) {
        data[i].reserve(env->SubsourceSize);
        std::ifstream in(SUBSOURCE_BIN_PREFIX + std::to_string(i) + ".bin");
        data[i].assign((std::istreambuf_iterator<char>(in)),
                (std::istreambuf_iterator<char>()) );
    }

    std::string result;
    result.reserve(env->SubsourceSize * env->SubsourceCnt);

    NBench::TSubsourceResponse response;

    for (auto _ : state) {
        response.Clear();
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.MergeFromString(data[i]);
        }

        result = response.SerializeAsString();
    }

    CheckSubsources(result);
}

static void BM_ProxyConcatSubsourcesLazy(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::vector<std::string> data(env->SubsourceCnt);

    for(size_t i = 0; i < data.size(); i++) {
        data[i].reserve(env->SubsourceSize);
        std::ifstream in(SUBSOURCE_BIN_PREFIX + std::to_string(i) + ".bin");
        data[i].assign((std::istreambuf_iterator<char>(in)),
                (std::istreambuf_iterator<char>()) );
    }

    std::string result;
    result.reserve(env->SubsourceSize * env->SubsourceCnt);

    NBench::TSubsourceResponseLazy response;

    for (auto _ : state) {
        response.Clear();
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.MergeFromString(data[i]);
        }

        result = response.SerializeAsString();
    }

    CheckSubsources(result);
}

// Register the function as a benchmark
//BENCHMARK(BM_ParseProtoFromFile)->src/google/protobuf/lazy_packed_field.hterations(20);
//BENCHMARK(BM_CopyWithoutParsing)->Iterations(20);
//BENCHMARK(BM_ParseFromString)->Iterations(20);
//BENCHMARK(BM_ParseProtoFromFileWithArena)->Iterations(20);
BENCHMARK(BM_LoadEnv)->Iterations(1)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_Memcpy)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_TestLazyFromString)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_TestFromString)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_TestTTestDefaultWork)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_TestTTestLazyDefaultWork)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_ProxyConcatSubsources)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_ProxyConcatSubsourcesLazy)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK_MAIN();