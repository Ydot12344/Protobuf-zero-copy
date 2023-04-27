#pragma once

#include <benchmark/benchmark.h>

namespace NBench2 {

void LoadEnv();

void BM_TestLazyDefaultWorkBig(benchmark::State& state);
void BM_TestLazyDefaultWorkMedium(benchmark::State& state);
void BM_TestLazyDefaultWorkSmall(benchmark::State& state);

void BM_TestDefaultWorkBig(benchmark::State& state);
void BM_TestDefaultWorkMedium(benchmark::State& state);
void BM_TestDefaultWorkSmall(benchmark::State& state);

} // namespace NBench1
