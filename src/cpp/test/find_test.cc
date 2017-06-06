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

#define G_POOL_SIZE          5
#define G_POOL_RANDOM true

int g_count = 0;

micro_set<int, TO_UP>*                      g_micro_set                      = new micro_set<int, TO_UP>();
micro_array_set<int, TO_UP>*           g_micro_array_set           = new micro_array_set<int, TO_UP>();
micro_tree_set<int, TO_UP>*             g_micro_tree_set             = new micro_tree_set<int, TO_UP>();
micro_unordered_set<int, TO_UP>* g_micro_unordered_set = new micro_unordered_set<int, TO_UP>();
micro_vector_set<int, TO_UP>*         g_micro_vector_set         =   new micro_vector_set<int, TO_UP>();

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

    if(g_count == 0)
    {
      for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      {
        g_micro_set->insert(g_array_random_insert[t_index]);
        g_micro_array_set->insert(g_array_random_insert[t_index]);
        g_micro_tree_set->insert(g_array_random_insert[t_index]);
        g_micro_unordered_set->insert(g_array_random_insert[t_index]);
        g_micro_vector_set->insert(g_array_random_insert[t_index]);
        }

        g_count++;
      }
}

BENCHMARK(generate_random);

void find_micro_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      g_micro_set->find(g_array_random_insert[t_index]);
  }
}

BENCHMARK(find_micro_set);

void find_micro_array_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      g_micro_array_set->find(g_array_random_insert[t_index]);
  }
}

BENCHMARK(find_micro_array_set);

void find_micro_tree_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      g_micro_tree_set->find(g_array_random_insert[t_index]);
  }
}

BENCHMARK(find_micro_tree_set);

void find_micro_unordered_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      g_micro_unordered_set->find(g_array_random_insert[t_index]);
  }
}

BENCHMARK(find_micro_unordered_set);

void find_micro_vector_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE / 2; t_index++)
      g_micro_vector_set->find(g_array_random_insert[t_index]);
  }
}

BENCHMARK(find_micro_vector_set);



BENCHMARK_MAIN()
