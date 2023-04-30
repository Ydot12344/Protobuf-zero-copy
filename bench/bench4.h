#pragma once

#include <benchmark/benchmark.h>

namespace NBench4 {

void LoadEnv();

void BM_TestLazyFromStreamBig(benchmark::State& state);
void BM_TestLazyFromStreamMedium(benchmark::State& state);
void BM_TestLazyFromStreamSmall(benchmark::State& state);

void BM_TestFromStreamBig(benchmark::State& state);
void BM_TestFromStreamMedium(benchmark::State& state);
void BM_TestFromStreamSmall(benchmark::State& state);

} // namespace NBench4
