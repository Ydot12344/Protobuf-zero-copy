#include "gen_data.h"

namespace NGenProto {

using namespace tutorial;

TReport GenReport(const TGenOpts& opts) {
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

void GenRepeatedWraper(TRepeatedWraper* val, const TGenOpts& opts) {
    for (size_t i = 0; i < opts.SetsOfFilesCount; i++) {
        GenFileSet(val->add_setsoffiles(), opts);
    }
}

void GenRepeatedWraper(TLazyField<TRepeatedWraper>* val, const TGenOpts& opts) {
    for (size_t i = 0; i < opts.SetsOfFilesCount; i++) {
        GenFileSet(val->Unpack()->add_setsoffiles(), opts);
    }
}

TTest GenTest(const TGenOpts& opts) {
    TTest res;
    GenRepeatedWraper(res.mutable_wraper(), opts);
    return res;
}

void GenFile(TFile* val, const TGenOpts& opts) {
    for (size_t i = 0; i < opts.FloatCount; i++) {
        val->add_weights(0.1f);
    }
    
    val->set_name(GenString(opts.StringSize));

    for (size_t i = 0; i < opts.NumsCount; i++) {
        val->add_hosts(rand() % 1000);
    }
}

void GenFileSet(TFileSet* val, const TGenOpts& opts) {
    val->set_hash(rand()%1000);

    for (size_t i = 0; i < opts.FilesCount; i++) {
        GenFile(val->add_files(), opts);
    }
}

std::string GenString(size_t size) {
    std::string s;
    for (size_t i = 0; i < size; i++) {
        s += (char)(rand()%128);
    }

    return s;
}
    
}
