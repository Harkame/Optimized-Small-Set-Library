#include <cstdlib>
#include <ctime>
#include <iostream>

#include "benchmark/benchmark_api.h"

#include "../implementation/inner_set.cpp"
#include "../implementation/inner_set_0.cpp"
#include "../implementation/inner_set_1.cpp"
#include "../implementation/inner_set_2.cpp"
#include "../implementation/inner_set_3.cpp"

#include "../implementation/inner_array_set.cpp"
#include "../implementation/inner_unordered_set.cpp"
#include "../implementation/inner_tree_set.cpp"
#include "../implementation/inner_vector_set.cpp"

#include "../implementation/micro_set.cpp"
#include "../implementation/micro_inner_set.cpp"
#include "../implementation/micro_unordered_set.cpp"
#include "../implementation/micro_tree_set.cpp"
#include "../implementation/micro_vector_set.cpp"

#include "../implementation/iterator_micro_set.cpp"

#define G_POOL_SIZE 3
#define G_POOL_RANDOM true

int g_array_random_retain[G_POOL_SIZE];

micro_set<int>*                      g_micro_set                      = new micro_set<int>();
micro_tree_set<int>*             g_micro_tree_set             = new micro_tree_set<int>();
micro_unordered_set<int>* g_micro_unordered_set = new micro_unordered_set<int>();
micro_vector_set<int>*         g_micro_vector_set         = new micro_vector_set<int>();

void generate_random(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    srand( (unsigned) time(nullptr));

    if(G_POOL_RANDOM)
      for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
        g_array_random_retain[t_index] = (rand() % G_POOL_SIZE) + 1;
      else
        for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
          g_array_random_retain[t_index] = t_index;
  }
}

BENCHMARK(generate_random);

void retain_micro_set(benchmark::State& state)
{
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      g_micro_set->retain(g_array_random_retain[t_index]);
}

BENCHMARK(retain_micro_set);

void retain_micro_tree_set(benchmark::State& state)
{
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      g_micro_tree_set->retain(g_array_random_retain[t_index]);
}

BENCHMARK(retain_micro_tree_set);

void retain_micro_unordered_set(benchmark::State& state)
{
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      g_micro_unordered_set->retain(g_array_random_retain[t_index]);
}

BENCHMARK(retain_micro_unordered_set);

void retain_micro_vector_set(benchmark::State& state)
{
  while (state.KeepRunning())
    for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      g_micro_vector_set->retain(g_array_random_retain[t_index]);
}

BENCHMARK(retain_micro_vector_set);


BENCHMARK_MAIN()
