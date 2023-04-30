#include "bench3.h"
#include "common.h"
#include "wraper.pb.h"
#include <gtest/gtest.h>
#include <gen_data.h>

#include <exception>

static std::vector<std::string> bigReportBin;
static std::vector<std::string> mediumReportBin;
static std::vector<std::string> smallReportBin; 

void NBench3::LoadEnv() {
    const auto& env = *TSingletone<TEnvHolder>();

    for (size_t i = 0; i < env->SubsourceCnt; i++) {
        bigReportBin.push_back(
              GenReportWraper(env->bigOpts).SerializeAsString()
        );
        mediumReportBin.push_back(
              GenReportWraper(env->mediumOpts).SerializeAsString()
        );
        smallReportBin.push_back(
              GenReportWraper(env->smallOpts).SerializeAsString()
        );
    }
}

void NBench3::BM_ProxyConcatSubsourcesLazyBig(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::array<NBench::TSubsourceResponseLazy, NUM_ITERATIONS> proxyResponses;
    std::string result;
    size_t iteration = 0;
    for(auto _ : state) {
        NBench::TReportWraperLazy response;
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.ParseFromString(bigReportBin[i]);
            *proxyResponses[iteration].add_reponses() = response.report();
        }
        result = proxyResponses[iteration++].SerializeAsString();
    }

    NBench::TSubsourceResponse proxyExpectedResponse;
    NBench::TReportWraper tmpResponse;

    for (size_t i = 0; i < env->SubsourceCnt; i++) {
        tmpResponse.ParseFromString(bigReportBin[i]);
        *proxyExpectedResponse.add_reponses() = tmpResponse.report();
    }

    assert(result == proxyExpectedResponse.SerializeAsString());
}
void NBench3::BM_ProxyConcatSubsourcesLazyMedium(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::array<NBench::TSubsourceResponseLazy, NUM_ITERATIONS> proxyResponses;
    std::string result;
    size_t iteration = 0;
    for(auto _ : state) {
        NBench::TReportWraperLazy response;
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.ParseFromString(mediumReportBin[i]);
            *proxyResponses[iteration].add_reponses() = response.report();
        }
        result = proxyResponses[iteration++].SerializeAsString();
    }

    NBench::TSubsourceResponse proxyExpectedResponse;
    NBench::TReportWraper tmpResponse;

    for (size_t i = 0; i < env->SubsourceCnt; i++) {
        tmpResponse.ParseFromString(mediumReportBin[i]);
        *proxyExpectedResponse.add_reponses() = tmpResponse.report();
    }

    assert(result == proxyExpectedResponse.SerializeAsString());
}
void NBench3::BM_ProxyConcatSubsourcesLazySmall(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::array<NBench::TSubsourceResponseLazy, NUM_ITERATIONS> proxyResponses;
    std::string result;
    size_t iteration = 0;
    for(auto _ : state) {
        NBench::TReportWraperLazy response;
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.ParseFromString(smallReportBin[i]);
            *proxyResponses[iteration].add_reponses() = response.report();
        }
        result = proxyResponses[iteration++].SerializeAsString();
    }

    NBench::TSubsourceResponse proxyExpectedResponse;
    NBench::TReportWraper tmpResponse;

    for (size_t i = 0; i < env->SubsourceCnt; i++) {
        tmpResponse.ParseFromString(smallReportBin[i]);
        *proxyExpectedResponse.add_reponses() = tmpResponse.report();
    }

    assert(result == proxyExpectedResponse.SerializeAsString());
}

void NBench3::BM_ProxyConcatSubsourcesBig(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::array<NBench::TSubsourceResponse, NUM_ITERATIONS> proxyResponses;
    NBench::TReportWraper response;
    std::string result;
    size_t iteration = 0;
    for(auto _ : state) {
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.ParseFromString(bigReportBin[i]);
            *proxyResponses[iteration].add_reponses() = response.report();
        }
        result = proxyResponses[iteration++].SerializeAsString();
    }

    assert(!result.empty());
}
void NBench3::BM_ProxyConcatSubsourcesMedium(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::array<NBench::TSubsourceResponse, NUM_ITERATIONS> proxyResponses;
    NBench::TReportWraper response;
    std::string result;
    size_t iteration = 0;
    for(auto _ : state) {
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.ParseFromString(mediumReportBin[i]);
            *proxyResponses[iteration].add_reponses() = response.report();
        }
        result = proxyResponses[iteration++].SerializeAsString();
    }

    assert(!result.empty());
}
void NBench3::BM_ProxyConcatSubsourcesSmall(benchmark::State& state) {
    const auto& env = *TSingletone<TEnvHolder>();

    std::array<NBench::TSubsourceResponse, NUM_ITERATIONS> proxyResponses;
    NBench::TReportWraper response;
    std::string result;
    size_t iteration = 0;
    for(auto _ : state) {
        for (size_t i = 0; i < env->SubsourceCnt; i++) {
            response.ParseFromString(smallReportBin[i]);
            *proxyResponses[iteration].add_reponses() = response.report();
        }
        result = proxyResponses[iteration++].SerializeAsString();
    }

    assert(!result.empty());
}