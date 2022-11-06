#include "messge.pb.h"
#include <benchmark/benchmark.h>
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

        NGenProto::TGenOpts opts;
        opts.NumsCount = 100;
        opts.StringsCount = 100;
        opts.StringSize = 100;
        opts.FloatCount = 100;
        opts.FilesCount = 2000;
        opts.SetsOfFilesCount = 100;

        report =  NGenProto::GenReport(opts);

        std::string out; 
        report.SerializeToString(&out);
    }

    tutorial::TReport report;
};

static void BM_ParseProtoFromFile(benchmark::State& state) {

    const auto& env = *TSingletone<TEnvHolder>();
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

        std::ofstream out("res.txt");
        res.SerializeToOstream(&out);
    }
    
}
// Register the function as a benchmark
BENCHMARK(BM_ParseProtoFromFile);
BENCHMARK_MAIN();