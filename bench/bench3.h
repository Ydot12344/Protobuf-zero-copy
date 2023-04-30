#pragma once

#include <benchmark/benchmark.h>

namespace NBench3 {

void LoadEnv();

void BM_ProxyConcatSubsourcesLazyBig(benchmark::State& state);
void BM_ProxyConcatSubsourcesLazyMedium(benchmark::State& state);
void BM_ProxyConcatSubsourcesLazySmall(benchmark::State& state);

void BM_ProxyConcatSubsourcesBig(benchmark::State& state);
void BM_ProxyConcatSubsourcesMedium(benchmark::State& state);
void BM_ProxyConcatSubsourcesSmall(benchmark::State& state);

} // namespace NBench3
