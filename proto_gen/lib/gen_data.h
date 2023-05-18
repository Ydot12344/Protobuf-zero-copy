#pragma once
#include "common.pb.h"
#include "wraper.pb.h"
#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json; 

namespace NGenProto {

struct TGenOpts {
    size_t Seed = 0;
    size_t NumsCount = 0;
    size_t StringsCount = 0;
    size_t FloatCount = 0;
    size_t StringSize = 0;
    size_t FilesCount = 0;
    size_t SetsOfFilesCount = 0;

    void FromJson(const json& config) {
        Seed = config["Seed"];
        NumsCount = config["NumsCount"];
        StringsCount = config["StringsCount"];
        FloatCount = config["FloatCount"];
        StringSize = config["StringSize"];
        FilesCount = config["FilesCount"];
        SetsOfFilesCount = config["SetsOfFilesCount"];
    }
};

std::string GenString(size_t size);

NBench::TReport GenReport(const TGenOpts& opts);
NBench::TReportWraper GenReportWraper(const TGenOpts& opts);

void GenFileSet(NBench::TFileSet* val, const TGenOpts& opts);
void GenFile(NBench::TFile* val, const TGenOpts& opts);

} //namespace NGenProto
