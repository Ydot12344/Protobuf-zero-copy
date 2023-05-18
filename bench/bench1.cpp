#include "bench1.h"
#include "common.h"
#include "wraper.pb.h"
#include <gen_data.h>

#include <exception>
#include <iomanip>

static std::string bigReportBin;
static std::string mediumReportBin;
static std::string smallReportBin;

void NBench1::LoadEnv() {
    const auto& env = *TSingletone<TEnvHolder>();

    bigReportBin = NGenProto::GenReportWraper(env->bigOpts).SerializeAsString();
    mediumReportBin = NGenProto::GenReportWraper(env->mediumOpts).SerializeAsString();
    smallReportBin = NGenProto::GenReportWraper(env->smallOpts).SerializeAsString();

    std::cout << "Big    - " << SizeFormat(bigReportBin.size()) << std::endl;
    std::cout << "Medium - " << SizeFormat(mediumReportBin.size()) << std::endl;
    std::cout << "Small  - " << SizeFormat(smallReportBin.size()) << std::endl;
}

void NBench1::BM_TestLazyFromStringBig(benchmark::State& state) {
    NBench::TReportWraperLazy wraper;

    std::string result;
    for (auto _ : state) {
        wraper.ParseFromString(bigReportBin);
        result = wraper.SerializeAsString();
    }

    if (result != bigReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }
}

void NBench1::BM_TestLazyFromStringMedium(benchmark::State& state) {
    NBench::TReportWraperLazy wraper;

    std::string result;
    for (auto _ : state) {
        wraper.ParseFromString(mediumReportBin);
        result = wraper.SerializeAsString();
    }

    if (result != mediumReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }
}

void NBench1::BM_TestLazyFromStringSmall(benchmark::State& state) {
    NBench::TReportWraperLazy wraper;

    std::string result;
    for (auto _ : state) {
        wraper.ParseFromString(smallReportBin);
        result = wraper.SerializeAsString();
    }

    if (result != smallReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }
}

void NBench1::BM_TestFromStringBig(benchmark::State& state) {
    NBench::TReportWraper wraper;

    std::string result;
    for (auto _ : state) {
        wraper.ParseFromString(bigReportBin);
        result = wraper.SerializeAsString();
    }

    if (result != bigReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }
}

void NBench1::BM_TestFromStringMedium(benchmark::State& state) {
    NBench::TReportWraper wraper;

    std::string result;
    for (auto _ : state) {
        wraper.ParseFromString(mediumReportBin);
        result = wraper.SerializeAsString();
    }

    if (result != mediumReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }
}

void NBench1::BM_TestFromStringSmall(benchmark::State& state) {
    NBench::TReportWraper wraper;

    std::string result;
    for (auto _ : state) {
        wraper.ParseFromString(smallReportBin);
        result = wraper.SerializeAsString();
    }

    if (result != smallReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }
}

void NBench1::BM_MemcpyBig(benchmark::State& state) {
    char* arr = new char[bigReportBin.size()];

    for (auto _ : state) {
        memcpy(arr, bigReportBin.data(), bigReportBin.size());
    }

    if (std::string(arr, bigReportBin.size()) != bigReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }

    delete[] arr;
}

void NBench1::BM_MemcpyMedium(benchmark::State& state) {
    char* arr = new char[mediumReportBin.size()];

    for (auto _ : state) {
        memcpy(arr, mediumReportBin.data(), mediumReportBin.size());
    }

    if (std::string(arr, mediumReportBin.size()) != mediumReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }

    delete[] arr;
}

void NBench1::BM_MemcpySmall(benchmark::State& state) {
    char* arr = new char[smallReportBin.size()];

    for (auto _ : state) {
        memcpy(arr, smallReportBin.data(), smallReportBin.size());
    }

    if (std::string(arr, smallReportBin.size()) != smallReportBin) {
        throw std::runtime_error("NOT EQUAL");
    }

    delete[] arr;
}
