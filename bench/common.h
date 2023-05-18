#pragma once

#include <gen_data.h>
#include <nlohmann/json.hpp>

#include <fstream>

using json = nlohmann::json;

constexpr int NUM_ITERATIONS = 20;

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

        std::ifstream stream("config.json");
        json config = json::parse(stream);

        auto bigProto = config["big_proto"];
        auto mediumProto = config["medium_proto"];
        auto smallProto = config["small_proto"];
        SubsourceCnt = config["subsource_cnt"];
        
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

static std::string SizeFormat(size_t size) {
    std::string suff = "byte";
    double del = 1;
    if (size >= (1 << 10)) {
        del *= 1024;
        suff = "KB";
    }
    if (size >= (1 << 20)) {
        del *= 1024;
        suff = "MB";
    }
    if (size >= (1 << 30)) {
        del *= 1024;
        suff = "GB";
    }

    std::string res;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << size / del;
    stream >> res;

    return res + " " + suff;
}
