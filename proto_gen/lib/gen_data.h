#pragma once
#include "messge.pb.h"
#include <string>

namespace NGenProto {

struct TGenOpts {
    size_t Seed = 0;
    size_t NumsCount = 0;
    size_t StringsCount = 0;
    size_t FloatCount = 0;
    size_t StringSize = 0;
    size_t FilesCount = 0;
    size_t SetsOfFilesCount = 0;
};

std::string GenString(size_t size);
tutorial::TReport GenReport(const TGenOpts& opts);
void GenFileSet(tutorial::TFileSet* val, const TGenOpts& opts);
void GenFile(tutorial::TFile* val, const TGenOpts& opts);

}