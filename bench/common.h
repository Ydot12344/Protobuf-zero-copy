#pragma once

#include <gen_data.h>
#include <nlohmann/json.hpp>

#include <fstream>

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
        auto mediumProto = config["medium_proto"];
        auto smallProto = config["small_proto"];
        
        smallOpts.FromJson(smallProto);
        mediumOpts.FromJson(mediumProto);
        bigOpts.FromJson(bigProto);
    }

    size_t TestBinSize;
    size_t ReportBinSize;
    size_t SubsourceSize;
    size_t SubsourceCnt;

    NGenProto::TGenOpts smallOpts;
    NGenProto::TGenOpts mediumOpts;
    NGenProto::TGenOpts bigOpts;
private:
    size_t BigProtoSize;
    size_t SmallProtoSize;
};
