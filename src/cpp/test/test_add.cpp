#include "benchmark/benchmark_api.h"
#include "inner_hashset.cpp"
#include "inner_vector_set.cpp"

void inner_hashset(benchmark::State& state) {
  inner_hashset<int>* in = new inner_hashset<int>();
  in->add_element(42);
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(state.iterations());
  }
}
BENCHMARK(inner_hashset);

void inner_vector_set(benchmark::State& state) {
  inner_vector_set<int>* in = new inner_vector_set<int>();
  in->add_element(42);
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(state.iterations());
  }
}
BENCHMARK(inner_vector_set);

BENCHMARK_MAIN()
