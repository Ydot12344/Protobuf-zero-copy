#include "bench1.h"
#include "bench2.h"
#include "bench3.h"
#include "bench4.h"
#include "common.h"

static void BM_LoadEnv(benchmark::State& state) {
    NBench1::LoadEnv();
    NBench2::LoadEnv();
    NBench3::LoadEnv();
    NBench4::LoadEnv();
}

// Load env
BENCHMARK(BM_LoadEnv)->Iterations(1)->Unit(benchmark::kMillisecond);

// no payload benchs
BENCHMARK(NBench1::BM_MemcpySmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_MemcpyMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_MemcpyBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench1::BM_TestFromStringBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestFromStringMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestFromStringSmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench1::BM_TestLazyFromStringBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestLazyFromStringMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench1::BM_TestLazyFromStringSmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

// Test overhead
BENCHMARK(NBench2::BM_TestDefaultWorkBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestDefaultWorkMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestDefaultWorkSmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench2::BM_TestLazyDefaultWorkBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestLazyDefaultWorkMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench2::BM_TestLazyDefaultWorkSmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

// Proxy test
BENCHMARK(NBench3::BM_ProxyConcatSubsourcesLazyBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench3::BM_ProxyConcatSubsourcesLazyMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench3::BM_ProxyConcatSubsourcesLazySmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench3::BM_ProxyConcatSubsourcesBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench3::BM_ProxyConcatSubsourcesMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench3::BM_ProxyConcatSubsourcesSmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

// Test ParseFromStream
BENCHMARK(NBench4::BM_TestLazyFromStreamBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench4::BM_TestLazyFromStreamMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench4::BM_TestLazyFromStreamSmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK(NBench4::BM_TestFromStreamBig)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench4::BM_TestFromStreamMedium)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);
BENCHMARK(NBench4::BM_TestFromStreamSmall)->Iterations(NUM_ITERATIONS)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();