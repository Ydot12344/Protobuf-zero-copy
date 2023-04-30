#include "bench4.h"
#include "common.h"
#include "wraper.pb.h"
#include <gtest/gtest.h>
#include <gen_data.h>

#include <exception>

static std::string bigReportBin;
static std::string mediumReportBin;
static std::string smallReportBin; 

void NBench4::LoadEnv() {
    const auto& env = *TSingletone<TEnvHolder>();

    bigReportBin = NGenProto::GenReportWraper(env->bigOpts).SerializeAsString();
    mediumReportBin = NGenProto::GenReportWraper(env->mediumOpts).SerializeAsString();
    smallReportBin = NGenProto::GenReportWraper(env->smallOpts).SerializeAsString();
}

void NBench4::BM_TestLazyFromStreamBig(benchmark::State& state) {
    std::array<std::stringstream,NUM_ITERATIONS> ss;
    for (size_t i = 0; i < NUM_ITERATIONS; i++) {
        ss[i] = std::stringstream(bigReportBin);
    }
    size_t i = 0;
    NBench::TReportWraperLazy wraper;
    std::string result;
    for (auto _: state) {
        wraper.ParseFromIstream(&ss[i++]);
        result = wraper.SerializeAsString();
    }

    std::stringstream tmpSS(bigReportBin);
    NBench::TReportWraper tmpWraper;
    tmpWraper.ParseFromIstream(&tmpSS);
    assert(result == tmpWraper.SerializePartialAsString());
}
void NBench4::BM_TestLazyFromStreamMedium(benchmark::State& state) {
    std::array<std::stringstream,NUM_ITERATIONS> ss;
    for (size_t i = 0; i < NUM_ITERATIONS; i++) {
        ss[i] = std::stringstream(mediumReportBin);
    }
    size_t i = 0;
    NBench::TReportWraperLazy wraper;
    std::string result;
    for (auto _: state) {
        wraper.ParseFromIstream(&ss[i++]);
        result = wraper.SerializeAsString();
    }

    std::stringstream tmpSS(mediumReportBin);
    NBench::TReportWraper tmpWraper;
    tmpWraper.ParseFromIstream(&tmpSS);
    assert(result == tmpWraper.SerializePartialAsString());
}
void NBench4::BM_TestLazyFromStreamSmall(benchmark::State& state) {
    std::array<std::stringstream,NUM_ITERATIONS> ss;
    for (size_t i = 0; i < NUM_ITERATIONS; i++) {
        ss[i] = std::stringstream(smallReportBin);
    }
    size_t i = 0;
    NBench::TReportWraperLazy wraper;
    std::string result;
    for (auto _: state) {
        wraper.ParseFromIstream(&ss[i++]);
        result = wraper.SerializeAsString();
    }

    std::stringstream tmpSS(smallReportBin);
    NBench::TReportWraper tmpWraper;
    tmpWraper.ParseFromIstream(&tmpSS);
    assert(result == tmpWraper.SerializePartialAsString());
}

void NBench4::BM_TestFromStreamBig(benchmark::State& state) {
    std::array<std::stringstream,NUM_ITERATIONS> ss;
    for (size_t i = 0; i < NUM_ITERATIONS; i++) {
        ss[i] = std::stringstream(bigReportBin);
    }
    size_t i = 0;
    NBench::TReportWraper wraper;
    std::string result;
    for (auto _: state) {
        wraper.ParseFromIstream(&ss[i++]);
        result = wraper.SerializeAsString();
    }
}
void NBench4::BM_TestFromStreamMedium(benchmark::State& state) {
    std::array<std::stringstream,NUM_ITERATIONS> ss;
    for (size_t i = 0; i < NUM_ITERATIONS; i++) {
        ss[i] = std::stringstream(mediumReportBin);
    }
    size_t i = 0;
    NBench::TReportWraper wraper;
    std::string result;
    for (auto _: state) {
        wraper.ParseFromIstream(&ss[i++]);
        result = wraper.SerializeAsString();
    }
}
void NBench4::BM_TestFromStreamSmall(benchmark::State& state) {
    std::array<std::stringstream,NUM_ITERATIONS> ss;
    for (size_t i = 0; i < NUM_ITERATIONS; i++) {
        ss[i] = std::stringstream(smallReportBin);
    }
    size_t i = 0;
    NBench::TReportWraper wraper;
    std::string result;
    for (auto _: state) {
        wraper.ParseFromIstream(&ss[i++]);
        result = wraper.SerializeAsString();
    }
}