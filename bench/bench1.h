#pragma once

#include <benchmark/benchmark.h>

namespace NBench1 {

void LoadEnv();

void BM_TestLazyFromStringBig(benchmark::State& state);
void BM_TestLazyFromStringMedium(benchmark::State& state);
void BM_TestLazyFromStringSmall(benchmark::State& state);

void BM_TestFromStringBig(benchmark::State& state);
void BM_TestFromStringMedium(benchmark::State& state);
void BM_TestFromStringSmall(benchmark::State& state);

void BM_MemcpyBig(benchmark::State& state);
void BM_MemcpyMedium(benchmark::State& state);
void BM_MemcpySmall(benchmark::State& state);

} // namespace NBench1
