#include <cstdlib>
#include <ctime>
#include <iostream>

#include "benchmark/benchmark_api.h"

#include "../implementation/inner_set.cpp"
#include "../implementation/inner_set_0.cpp"
#include "../implementation/inner_set_1.cpp"
#include "../implementation/inner_set_2.cpp"
#include "../implementation/inner_set_3.cpp"
#include "../implementation/inner_set_4.cpp"
#include "../implementation/inner_set_5.cpp"
#include "../implementation/inner_set_6.cpp"
#include "../implementation/inner_set_7.cpp"
#include "../implementation/inner_set_8.cpp"
#include "../implementation/inner_set_9.cpp"
#include "../implementation/inner_set_10.cpp"
#include "../implementation/inner_set_11.cpp"
#include "../implementation/inner_set_12.cpp"
#include "../implementation/inner_set_13.cpp"
#include "../implementation/inner_set_14.cpp"
#include "../implementation/inner_set_15.cpp"
#include "../implementation/inner_set_16.cpp"
#include "../implementation/inner_set_17.cpp"
#include "../implementation/inner_set_18.cpp"
#include "../implementation/inner_set_19.cpp"

#include "../implementation/inner_array_set.cpp"
#include "../implementation/inner_tree_set.cpp"
#include "../implementation/inner_unordered_set.cpp"
#include "../implementation/others/inner_vector_set.cpp"

#include "../implementation/micro_set.cpp"
#include "../implementation/others/micro_array_set.cpp"
#include "../implementation/others/micro_tree_set.cpp"
#include "../implementation/others/micro_unordered_set.cpp"
#include "../implementation/others/micro_vector_set.cpp"

#include "../implementation/iterator_micro_set.cpp"

#include <unistd.h>

#define TO_UP 19

#define G_POOL_SIZE          15
#define G_POOL_RANDOM true

int g_array_random_insert[G_POOL_SIZE];

void generate_random(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    srand( (unsigned) time(nullptr));

    if(G_POOL_RANDOM)
      for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
        g_array_random_insert[t_index] = (rand() % G_POOL_SIZE) + 1;
    else
      for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
        g_array_random_insert[t_index] = t_index;
    }
}

BENCHMARK(generate_random);

void erase_micro_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    state.PauseTiming();
    micro_set<int, TO_UP> t_micro_set;

    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      t_micro_set.insert(g_array_random_insert[t_index]);

    state.ResumeTiming();

    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      t_micro_set.erase(g_array_random_insert[t_index]);
  }
}

BENCHMARK(erase_micro_set);

void erase_micro_array_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    state.PauseTiming();
    micro_array_set<int, TO_UP> t_micro_array_set;

    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      t_micro_array_set.insert(g_array_random_insert[t_index]);
    state.ResumeTiming();

    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      t_micro_array_set.erase(g_array_random_insert[t_index]);
  }
}

BENCHMARK(erase_micro_array_set);

void erase_micro_tree_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    state.PauseTiming();
    micro_tree_set<int, TO_UP> t_micro_tree_set;

    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      t_micro_tree_set.insert(g_array_random_insert[t_index]);

    state.ResumeTiming();

    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      t_micro_tree_set.erase(g_array_random_insert[t_index]);
  }
}

BENCHMARK(erase_micro_tree_set);

void erase_micro_unordered_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    state.PauseTiming();
    micro_unordered_set<int, TO_UP> t_micro_unordered_set;

    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      t_micro_unordered_set.insert(g_array_random_insert[t_index]);

    state.ResumeTiming();

    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      t_micro_unordered_set.erase(g_array_random_insert[t_index]);
  }
}

BENCHMARK(erase_micro_unordered_set);

void erase_micro_vector_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    state.PauseTiming();
    micro_vector_set<int, TO_UP> t_micro_vector_set;

    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      t_micro_vector_set.insert(g_array_random_insert[t_index]);

    state.ResumeTiming();

    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      t_micro_vector_set.erase(g_array_random_insert[t_index]);
  }
}

BENCHMARK(erase_micro_vector_set);

BENCHMARK_MAIN()
