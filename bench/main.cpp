#include "bench1.h"
#include "bench2.h"

// void CheckFilesEqual(const NBench::TFile& a, const NBench::TFile& b) {
//     ASSERT_EQ(a.name(), b.name());
//     ASSERT_EQ(a.weights_size(), b.weights_size());
//     ASSERT_EQ(a.hosts_size(), b.hosts_size());

//     for (size_t i = 0; i < a.weights_size(); i++) {
//         ASSERT_EQ(a.weights(i), b.weights(i));
//     }

//     for (size_t i = 0; i < a.hosts_size(); i++) {
//         ASSERT_EQ(a.hosts(i), b.hosts(i));
//     }
// }

// void CheckSetsOfFilesEqual(const NBench::TFileSet& a, const NBench::TFileSet& b) {
//     ASSERT_EQ(a.hash(), b.hash());

//     ASSERT_EQ(a.files_size(), b.files_size());

//     for (size_t i = 0; i < a.files_size(); i++) {
//         CheckFilesEqual(a.files(i), b.files(i));
//     }
// }

// void CheckSubsources(const std::string& result) {
//     const auto& env = *TSingletone<TEnvHolder>();
//     std::vector<NBench::TSubsourceResponse> subsources(env->SubsourceCnt);

//     for (size_t i = 0; i < subsources.size(); i++) {
//         std::ifstream in(SUBSOURCE_BIN_PREFIX + std::to_string(i) + ".bin");
//         subsources[i].ParseFromIstream(&in);
//     }

//     NBench::TSubsourceResponse expected;
//     for (size_t i = 0; i < subsources.size(); i++) {
//         for (const auto& response : subsources[i].responses()) {
//             (*expected.add_responses()) = response;
//         }
//     }

//     ASSERT_EQ(result, expected.SerializeAsString());
// } 

// void Check(const std::string& resultBin) {
//     const auto& env = *TSingletone<TEnvHolder>();

//     NBench::TReport expected = env->report;
//     NBench::TReport result;

//     result.ParseFromString(resultBin);

//     ASSERT_EQ(result.nums_size(), 0);
//     ASSERT_EQ(result.strings_size(), 0);
//     ASSERT_EQ(result.setsoffiles_size(), env->bigOpts.SetsOfFilesCount / 2);

//     std::vector<NBench::TFileSet> sets;

//     for (size_t i = 0; i < expected.setsoffiles_size(); i++) {
//         sets.push_back(expected.setsoffiles(i));
//     }

//     std::sort(sets.begin(), sets.end(), 
//         [](const auto& a, const auto& b) {
//             return a.hash() > b.hash();
//         }
//     );

//     for (size_t i = 0; i < result.setsoffiles_size(); i++) {
//         CheckSetsOfFilesEqual(sets[i], result.setsoffiles(i));
//     }
// }

static void BM_LoadEnv(benchmark::State& state) {
    NBench1::LoadEnv();
    NBench2::LoadEnv();
}

// static void BM_TestTTestDefaultWork(benchmark::State& state) {
//     const auto& env = *TSingletone<TEnvHolder>();

//     std::string out, input;
//     input.reserve(env->TestBinSize);
//     out.reserve(env->TestBinSize);

//     std::ifstream in(TEST_BIN_PATH);
//     input.assign((std::istreambuf_iterator<char>(in) ),
//                 (std::istreambuf_iterator<char>()    ) );

//     NBench::TTest a;

//     for (auto _ : state) {
//         a.ParseFromString(input);
//         auto* file_set = a.mutable_wraper()->mutable_setsoffiles(0);
//         file_set->set_hash(0);
//         file_set->mutable_files(0)->set_name("rename_0");
//         a.SerializeToString(&out);
//     }
// }

// static void BM_TestTTestLazyDefaultWork(benchmark::State& state) {
//     const auto& env = *TSingletone<TEnvHolder>();

//     std::string out, input;
//     input.reserve(env->TestBinSize);
//     out.reserve(env->TestBinSize);

//     std::ifstream in(TEST_BIN_PATH);
//     input.assign((std::istreambuf_iterator<char>(in) ),
//                 (std::istreambuf_iterator<char>()    ) );

//     NBench::TTestLazy a;

//     for (auto _ : state) {
//         a.ParseFromString(input);
//         auto* file_set = a.mutable_wraper()->Unpack()->mutable_setsoffiles(0);
//         file_set->set_hash(0);
//         file_set->mutable_files(0)->set_name("rename_0");
//         a.SerializeToString(&out);
//     }

//     // Check
//     NBench::TTest b;
//     b.ParseFromString(input);
//     auto* file_set = b.mutable_wraper()->mutable_setsoffiles(0);
//     file_set->set_hash(0);
//     file_set->mutable_files(0)->set_name("rename_0");
//     std::string out_b;
//     b.SerializeToString(&out_b);

//     ASSERT_EQ(out, out_b);
// }


// static void BM_ProxyConcatSubsources(benchmark::State& state) {
//     const auto& env = *TSingletone<TEnvHolder>();

//     std::vector<std::string> data(env->SubsourceCnt);

//     for(size_t i = 0; i < data.size(); i++) {
//         data[i].reserve(env->SubsourceSize);
//         std::ifstream in(SUBSOURCE_BIN_PREFIX + std::to_string(i) + ".bin");
//         data[i].assign((std::istreambuf_iterator<char>(in)),
//                 (std::istreambuf_iterator<char>()) );
//     }

//     std::string result;
//     result.reserve(env->SubsourceSize * env->SubsourceCnt);

//     NBench::TSubsourceResponse response;

//     for (auto _ : state) {
//         response.Clear();
//         for (size_t i = 0; i < env->SubsourceCnt; i++) {
//             response.MergeFromString(data[i]);
//         }

//         result = response.SerializeAsString();
//     }

//     CheckSubsources(result);
// }

// static void BM_ProxyConcatSubsourcesLazy(benchmark::State& state) {
//     const auto& env = *TSingletone<TEnvHolder>();

//     std::vector<std::string> data(env->SubsourceCnt);

//     for(size_t i = 0; i < data.size(); i++) {
//         data[i].reserve(env->SubsourceSize);
//         std::ifstream in(SUBSOURCE_BIN_PREFIX + std::to_string(i) + ".bin");
//         data[i].assign((std::istreambuf_iterator<char>(in)),
//                 (std::istreambuf_iterator<char>()) );
//     }

//     std::string result;
//     result.reserve(env->SubsourceSize * env->SubsourceCnt);

//     NBench::TSubsourceResponseLazy response;

//     for (auto _ : state) {
//         response.Clear();
//         for (size_t i = 0; i < env->SubsourceCnt; i++) {
//             response.MergeFromString(data[i]);
//         }

//         result = response.SerializeAsString();
//     }

//     CheckSubsources(result);
// }

// static void BM_ParseFromStringStreamDefault(benchmark::State& state) {
//     const auto& env = *TSingletone<TEnvHolder>();
//     std::string data;
//     data.reserve(env->TestBinSize);

//     std::ifstream in(TEST_BIN_PATH);
//     data.assign((std::istreambuf_iterator<char>(in)),
//                 (std::istreambuf_iterator<char>()));

//     NBench::TTest a;
//     for (auto _ : state) {
//         std::stringstream ss(data);
//         a.ParseFromIstream(&ss);
//     }

//     std::string result;
//     a.SerializeToString(&result);
//     ASSERT_EQ(result, data);
// }

// static void BM_ParseFromStringStreamLazy(benchmark::State& state) {
//     const auto& env = *TSingletone<TEnvHolder>();
//     std::string data;
//     data.reserve(env->TestBinSize);

//     std::ifstream in(TEST_BIN_PATH);
//     data.assign((std::istreambuf_iterator<char>(in)),
//                 (std::istreambuf_iterator<char>()));


//     NBench::TTestLazy a;
//     for (auto _ : state) {
//         std::stringstream ss(data);
//         a.ParseFromIstream(&ss);
//     }

//     std::string result;
//     a.SerializeToString(&result);
//     ASSERT_EQ(result, data);
// }

// Load env
BENCHMARK(BM_LoadEnv)->Iterations(1)->Unit(benchmark::kMillisecond);

// no payload benchs
BENCHMARK(NBench1::BM_MemcpySmall)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_MemcpyMedium)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_MemcpyBig)->Iterations(20)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench1::BM_TestFromStringBig)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestFromStringMedium)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestFromStringSmall)->Iterations(20)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench1::BM_TestLazyFromStringBig)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestLazyFromStringMedium)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestLazyFromStringSmall)->Iterations(20)->Unit(benchmark::kMillisecond);

// Test overhead
BENCHMARK(NBench2::BM_TestDefaultWorkBig)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestDefaultWorkMedium)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestDefaultWorkSmall)->Iterations(20)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench2::BM_TestLazyDefaultWorkBig)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestLazyDefaultWorkMedium)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestLazyDefaultWorkSmall)->Iterations(20)->Unit(benchmark::kMillisecond);


// // test unpack perf
// BENCHMARK(BM_TestTTestDefaultWork)->Iterations(20)->Unit(benchmark::kMillisecond);
// BENCHMARK(BM_TestTTestLazyDefaultWork)->Iterations(20)->Unit(benchmark::kMillisecond);

// // test repeated merge
// BENCHMARK(BM_ProxyConcatSubsources)->Iterations(20)->Unit(benchmark::kMillisecond);
// BENCHMARK(BM_ProxyConcatSubsourcesLazy)->Iterations(20)->Unit(benchmark::kMillisecond);

// // test istream optimizaton
// BENCHMARK(BM_ParseFromStringStreamDefault)->Iterations(20)->Unit(benchmark::kMillisecond);
// BENCHMARK(BM_ParseFromStringStreamLazy)->Iterations(20)->Unit(benchmark::kMillisecond);
BENCHMARK_MAIN();