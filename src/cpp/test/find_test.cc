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

#define G_POOL_SIZE          30
#define G_POOL_RANDOM true

int g_array_random_insert[G_POOL_SIZE];
int g_array_random_find[G_POOL_SIZE];

micro_inner_set<int>*           g_micro_inner_set;
micro_array_set<int>*           g_micro_array_set;
micro_tree_set<int>*             g_micro_tree_set;
micro_unordered_set<int>* g_micro_unordered_set;
micro_vector_set<int>*         g_micro_vector_set;

bool g_already_insert = false;

void generate_random(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    srand( (unsigned) time(nullptr));

    if(G_POOL_RANDOM)
      for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
      {
          g_array_random_insert[t_index] = t_index;
        g_array_random_find[t_index] = (rand() % G_POOL_SIZE) + 1;
      }
      else
        for(int t_index = 0; t_index < G_POOL_SIZE / 2; t_index++)
        {
          g_array_random_insert[t_index] = t_index;
          g_array_random_find[t_index] = t_index;
        }

      if(g_already_insert == false)
      {
        g_already_insert = true;

        g_micro_inner_set           = new micro_inner_set<int>();
        g_micro_array_set           = new micro_array_set<int>();
        g_micro_tree_set             = new micro_tree_set<int>();
        g_micro_unordered_set = new micro_unordered_set<int>();
        g_micro_vector_set         = new micro_vector_set<int>();

        for(int t_index = 0; t_index < G_POOL_SIZE; t_index++)
        {
          g_micro_inner_set->insert(g_array_random_insert[t_index] );
          g_micro_array_set->insert(g_array_random_insert[t_index] );
          g_micro_tree_set->insert(g_array_random_insert[t_index] );
          g_micro_unordered_set->insert(g_array_random_insert[t_index] );
          g_micro_vector_set->insert(g_array_random_insert[t_index] );
        }
      }
  }
}

BENCHMARK(generate_random);

void find_micro_inner_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      g_micro_inner_set->find(g_array_random_find[t_index] );
  }
}

BENCHMARK(find_micro_inner_set);

void find_micro_array_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      g_micro_array_set->find(g_array_random_find[t_index] );
  }
}

BENCHMARK(find_micro_array_set);

void find_micro_tree_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      g_micro_tree_set->find(g_array_random_find[t_index] );
  }
}

BENCHMARK(find_micro_tree_set);

void find_micro_unordered_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      g_micro_unordered_set->find(g_array_random_find[t_index] );
  }
}

BENCHMARK(find_micro_unordered_set);

void find_micro_vector_set(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for(int t_index=0; t_index < G_POOL_SIZE; t_index++)
      g_micro_vector_set->find(g_array_random_find[t_index] );
    }
}

BENCHMARK(find_micro_vector_set);

BENCHMARK_MAIN()
