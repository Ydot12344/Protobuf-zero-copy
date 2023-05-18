#include <iostream>
#include <string>
#include <fstream>

#include "common.pb.h"
#include "opts.h"
#include "gen_data.h"
#include "wraper.pb.h"

using namespace NBench;
using namespace NGenProto;

int main(int argc, char** argv) {
    TOpts opts;
    std::string seed;
    std::string outputFile;
    std::string numsCount;
    std::string stringsCount;
    std::string stringSize;
    std::string floatCount;
    std::string filesInSetCount;
    std::string setsOfFilesCount;

    opts.AddOpt("seed", &seed);
    opts.AddOpt("out", &outputFile);
    opts.AddOpt("nums_cnt", &numsCount);
    opts.AddOpt("strings_cnt", &stringsCount);
    opts.AddOpt("string_size", &stringSize);
    opts.AddOpt("float_cnt", &floatCount);
    opts.AddOpt("files_cnt", &filesInSetCount);
    opts.AddOpt("sets_cnt", &setsOfFilesCount);

    opts.Parse(argc, argv);

    TGenOpts genOpt;
    genOpt.NumsCount = stoui(numsCount);
    genOpt.StringsCount = stoui(stringsCount);
    genOpt.StringSize = stoui(stringSize);
    genOpt.FloatCount = stoui(floatCount);
    genOpt.SetsOfFilesCount = stoui(setsOfFilesCount);
    genOpt.FilesCount = stoui(filesInSetCount);

    srand(stoui(seed));

    TReport report = GenReport(genOpt);

    std::ofstream out(outputFile);

    out << report.SerializeAsString();
    out.close();
}