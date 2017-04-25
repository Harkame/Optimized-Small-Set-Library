#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <vector>

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

#include "micro_set.cpp"
#include "micro_unordered_set.cpp"
#include "micro_tree_set.cpp"

#include "iterator_inner_set.cpp"

 //#define MEGABYTE 1024L * 1024L
 #define POOL_SIZE                     15
 #define STOCK_SIZE                   1000
 #define LIST_SIZE                        500
 #define COUNT_TIRAGE             1000

 using namespace std;

vector<int> test_object;
vector<micro_set<int>* > g_stock_micro_set;
vector<micro_set<int>* > g_list_micro_set;
micro_set<int>* g_micro_set = new micro_set<int>();

vector<micro_unordered_set<int>* > g_stock_micro_unordored_set;
vector<micro_unordered_set<int>* > g_list_micro_unordored_set;
micro_unordered_set<int>* g_micro_unordered_set = new micro_unordered_set<int>();

int g_random_index_list [COUNT_TIRAGE];
int g_random_index_g_stock_micro_set [COUNT_TIRAGE];
int g_coung_object [STOCK_SIZE];

 void init(benchmark::State& state)
 {
   while (state.KeepRunning())
   {
     int i = 2;
    srand( (unsigned) time(nullptr));


    for (int i =  0; i< POOL_SIZE; i++)
     test_object.push_back((rand() % 100) + 1);


    for (int i =  0; i< COUNT_TIRAGE; i++)
    g_random_index_list[i] = (rand() % LIST_SIZE) + 1;


    for (int i =  0; i< COUNT_TIRAGE; i++)
     g_random_index_g_stock_micro_set[i] = (rand() % STOCK_SIZE) + 1;


    for (int i =  0; i< STOCK_SIZE; i++)
     g_coung_object[i] = (rand() % 4) + 1;

    for (int i = 0; i < STOCK_SIZE; i++)
    {
      for (int j = 0; j < g_coung_object[i]; j++)
      {
        g_micro_set->insert(test_object.at((rand() % STOCK_SIZE) + 1));
        g_micro_unordered_set->insert(test_object.at((rand() % STOCK_SIZE) + 1));

        g_stock_micro_set.push_back(g_micro_set);
        g_stock_micro_unordored_set.push_back(g_micro_unordered_set);
      }
  }

  for (int i = 0; i < LIST_SIZE; i++)
  {
   micro_set<int>* m = new micro_set<int>();
   g_list_micro_set.push_back(m);
  }
  }
 }

 BENCHMARK(init);

void tesg_propagation(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for (int i=0; i< COUNT_TIRAGE; i++)
    {
      int indice = g_random_index_list[i];
      micro_set<int>* increment = g_stock_micro_set.at(g_random_index_g_stock_micro_set[i]);

      for (int j = indice; j < LIST_SIZE && !increment->empty(); j++)
        increment = g_list_micro_set.at(j)->add_all_and_propagate(*increment);
    }
  }
}

BENCHMARK(tesg_propagation);

void tesg_micro_unordored_set_propagation(benchmark::State& state)
{
  while (state.KeepRunning())
  {
    for (int i=0; i< COUNT_TIRAGE; i++)
    {
      int indice = g_random_index_list[i];
      micro_unordered_set<int>* increment = g_stock_micro_unordored_set.at(g_random_index_g_stock_micro_set[i]);

      for (int j = indice; j < LIST_SIZE && !increment->empty(); j++)
        increment = g_list_micro_unordored_set.at(j)->add_all_and_propagate(*increment);
    }
  }
}

BENCHMARK(tesg_micro_unordored_set_propagation);

BENCHMARK_MAIN()
