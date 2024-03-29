#include "gen_data.h"

using namespace NBench;

TReport NGenProto::GenReport(const TGenOpts& opts) {
    srand(opts.Seed);
    
    TReport res;
    
    for (size_t i = 0; i < opts.SetsOfFilesCount; i++) {
        GenFileSet(res.add_setsoffiles(), opts);
    }

    for (size_t i = 0; i < opts.NumsCount; i++) {
        res.add_nums(rand()%1000);
    }

    for (size_t i = 0; i < opts.StringsCount; i++) {
        res.add_strings(GenString(opts.StringSize));
    }

    return res;
}

void NGenProto::GenFile(TFile* val, const TGenOpts& opts) {
    for (size_t i = 0; i < opts.FloatCount; i++) {
        val->add_weights(0.1f);
    }
    
    val->set_name(GenString(opts.StringSize));

    for (size_t i = 0; i < opts.NumsCount; i++) {
        val->add_hosts(rand() % 1000);
    }
}

void NGenProto::GenFileSet(TFileSet* val, const TGenOpts& opts) {
    val->set_hash(rand()%1000);

    for (size_t i = 0; i < opts.FilesCount; i++) {
        GenFile(val->add_files(), opts);
    }
}

std::string NGenProto::GenString(size_t size) {
    std::string s;
    for (size_t i = 0; i < size; i++) {
        s += (char)(rand()%128);
    }

    return s;
}

NBench::TReportWraper NGenProto::GenReportWraper(const TGenOpts& opts) {
    NBench::TReportWraper wraper;
    wraper.set_some_val(123);
    wraper.set_some_field(GenString(opts.StringSize));
    *wraper.mutable_report() = GenReport(opts);

    return wraper;
}
    
