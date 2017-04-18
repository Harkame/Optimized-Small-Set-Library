#include <cstdlib>
#include <ctime>
#include <iostream>

#include "benchmark/benchmark_api.h"

#include "inner_set_0.cpp"
#include "inner_set_1.cpp"
#include "inner_set_2.cpp"
#include "inner_set_3.cpp"
#include "inner_set_4.cpp"
#include "inner_set_5.cpp"

#include "inner_array_set.cpp"
#include "inner_unordered_set.cpp"
#include "inner_tree_set.cpp"
#include "inner_vector_set.cpp"

#include "micro_set.cpp"
#include "micro_unordered_set.cpp"
#include "micro_tree_set.cpp"
#include "micro_vector_set.cpp"

#define G_POOL_SIZE 50
#define G_POOL_RANDOM true

int g_array_random[G_POOL_SIZE];

void generate_random(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    srand( (unsigned) time(nullptr));

    if(G_POOL_RANDOM)
      for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
        g_array_random[t_index] = (rand() % G_POOL_SIZE) + 1;
      else
        for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
          g_array_random[t_index] = t_index;
  }
}

BENCHMARK(generate_random);

void insert_micro_set(benchmark::State& state)
{
  micro_set<int>* t_micro_set = new micro_set<int>();
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      t_micro_set->insert(g_array_random[t_index]);
}

BENCHMARK(insert_micro_set);
//BENCHMARK(insert_micro_set)->ThreadPerCpu();

void insert_micro_tree_set(benchmark::State& state) {
  micro_tree_set<int>* t_micro_tree_set = new micro_tree_set<int>();
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      t_micro_tree_set->insert(g_array_random[t_index]);
}

BENCHMARK(insert_micro_tree_set);
//BENCHMARK(insert_micro_tree_set)->ThreadPerCpu();

void insert_micro_unordered_set(benchmark::State& state) {
  micro_unordered_set<int>* t_micro_unordered_set = new micro_unordered_set<int>();
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      t_micro_unordered_set->insert(g_array_random[t_index]);
}

BENCHMARK(insert_micro_unordered_set);
//BENCHMARK(insert_micro_unordered_set)->ThreadPerCpu();

void insert_micro_vector_set(benchmark::State& state) {
  micro_vector_set<int>* t_micro_vector_set = new micro_vector_set<int>();
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      t_micro_vector_set->insert(g_array_random[t_index]);
}

BENCHMARK(insert_micro_vector_set);
//BENCHMARK(insert_micro_unordered_set)->ThreadPerCpu();


BENCHMARK_MAIN()
