#include "bench2.h"
#include "common.h"
#include "wraper.pb.h"
#include <gtest/gtest.h>
#include <gen_data.h>

#include <exception>

static std::string bigReportBin;
static std::string mediumReportBin;
static std::string smallReportBin;

void NBench2::LoadEnv() {
    const auto& env = *TSingletone<TEnvHolder>();

    bigReportBin = NGenProto::GenReportWraper(env->bigOpts).SerializeAsString();
    mediumReportBin = NGenProto::GenReportWraper(env->mediumOpts).SerializeAsString();
    smallReportBin = NGenProto::GenReportWraper(env->smallOpts).SerializeAsString();
}

void NBench2::BM_TestLazyDefaultWorkBig(benchmark::State& state) {
    NBench::TReportWraperLazy a;
    std::string result;
    for (auto _ : state) {
        a.ParseFromString(bigReportBin);
        auto* file_set = a.mutable_report()->Unpack()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        result = a.SerializeAsString();
    }

    NBench::TReportWraper tmp;
    tmp.ParseFromString(bigReportBin);
    auto* file_set = tmp.mutable_report()->mutable_setsoffiles(0);
    file_set->set_hash(0);
    file_set->mutable_files(0)->set_name("rename_0");

    assert(result == tmp.SerializeAsString());
}
void NBench2::BM_TestLazyDefaultWorkMedium(benchmark::State& state) {
    NBench::TReportWraperLazy a;
    std::string result;
    for (auto _ : state) {
        a.ParseFromString(mediumReportBin);
        auto* file_set = a.mutable_report()->Unpack()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        result = a.SerializeAsString();
    }

    NBench::TReportWraper tmp;
    tmp.ParseFromString(mediumReportBin);
    auto* file_set = tmp.mutable_report()->mutable_setsoffiles(0);
    file_set->set_hash(0);
    file_set->mutable_files(0)->set_name("rename_0");

    assert(result != tmp.SerializeAsString());
}
void NBench2::BM_TestLazyDefaultWorkSmall(benchmark::State& state) {
    NBench::TReportWraperLazy a;
    std::string result;
    for (auto _ : state) {
        a.ParseFromString(smallReportBin);
        auto* file_set = a.mutable_report()->Unpack()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        result = a.SerializeAsString();
    }

    NBench::TReportWraper tmp;
    tmp.ParseFromString(smallReportBin);
    auto* file_set = tmp.mutable_report()->mutable_setsoffiles(0);
    file_set->set_hash(0);
    file_set->mutable_files(0)->set_name("rename_0");

    assert(result != tmp.SerializeAsString());
}

void NBench2::BM_TestDefaultWorkBig(benchmark::State& state) {
    NBench::TReportWraper a;
    std::string result;
    for (auto _ : state) {
        a.ParseFromString(bigReportBin);
        auto* file_set = a.mutable_report()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        result = a.SerializeAsString();
    }
}
void NBench2::BM_TestDefaultWorkMedium(benchmark::State& state) {
    NBench::TReportWraper a;
    std::string result;
    for (auto _ : state) {
        a.ParseFromString(mediumReportBin);
        auto* file_set = a.mutable_report()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        result = a.SerializeAsString();
    }
}
void NBench2::BM_TestDefaultWorkSmall(benchmark::State& state) {
    NBench::TReportWraper a;
    std::string result;
    for (auto _ : state) {
        a.ParseFromString(smallReportBin);
        auto* file_set = a.mutable_report()->mutable_setsoffiles(0);
        file_set->set_hash(0);
        file_set->mutable_files(0)->set_name("rename_0");
        result = a.SerializeAsString();
    }
}