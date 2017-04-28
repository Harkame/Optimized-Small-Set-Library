#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <vector>

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
#include "micro_inner_set.cpp"
#include "micro_tree_set.cpp"
#include "micro_unordered_set.cpp"
#include "micro_vector_set.cpp"
#include "micro_array_set.cpp"

#include "iterator_inner_set.cpp"

 //#define MEGABYTE 1024L * 1024L
 #define POOL_SIZE         15
 #define STOCK_SIZE        10
 #define LIST_SIZE             50
 #define COUNT_TIRAGE 10
 #define ITERATION          1000

 using namespace std;
 using namespace std::chrono;

vector<int> test_object;

vector<micro_inner_set<int>* > g_stock_micro_inner_set;
vector<micro_inner_set<int>* > g_list_micro_inner_set;

vector<micro_unordered_set<int>* > g_stock_micro_unordored_set;
vector<micro_unordered_set<int>* > g_list_micro_unordored_set;

vector<micro_tree_set<int>* > g_stock_micro_tree_set;
vector<micro_tree_set<int>* > g_list_micro_tree_set;

vector<micro_vector_set<int>* > g_stock_micro_vector_set;
vector<micro_vector_set<int>* > g_list_micro_vector_set;

vector<micro_array_set<int>* > g_stock_micro_array_set;
vector<micro_array_set<int>* > g_list_micro_array_set;


int g_random_index_list[ITERATION][COUNT_TIRAGE];
int g_random_index_stock[ITERATION][COUNT_TIRAGE];
int g_count_object[STOCK_SIZE];

void init()
{
  srand( (unsigned) time(nullptr));

  for (int i =  0; i< POOL_SIZE; i++)
    test_object.push_back((rand() % 100) + 1);

  for (int t_iteration = 0; t_iteration < ITERATION; t_iteration++)
  {
    for (int i =  0; i< COUNT_TIRAGE; i++)
      g_random_index_list[t_iteration][i] = (rand() % LIST_SIZE) + 1;


    for (int i =  0; i< COUNT_TIRAGE; i++)
      g_random_index_stock[t_iteration][i] = (rand() % STOCK_SIZE);
  }

  for (int i =  0; i < STOCK_SIZE; i++)
    g_count_object[i] = (rand() % 4) + 1;

  for (int i = 0; i < STOCK_SIZE; i++)
  {
    micro_inner_set<int>*           t_micro_inner_set          = new micro_inner_set<int>();
    micro_unordered_set<int>* t_micro_unordered_set = new micro_unordered_set<int>();
    micro_tree_set<int>*             t_micro_tree_set             = new micro_tree_set<int>();
    micro_vector_set<int>*         t_micro_vector_set         = new micro_vector_set<int>();
    micro_array_set<int>*           t_micro_array_set           = new micro_array_set<int>();

    for (int j = 0; j < g_count_object[i]; j++)
    {
      int t_random = rand() % POOL_SIZE;

      t_micro_inner_set->insert(test_object.at(t_random));
      t_micro_unordered_set->insert(test_object.at(t_random));
      t_micro_tree_set->insert(test_object.at(t_random));
      t_micro_vector_set->insert(test_object.at(t_random));
      t_micro_array_set->insert(test_object.at(t_random));
    }

    g_stock_micro_inner_set.push_back(t_micro_inner_set);
    g_stock_micro_unordored_set.push_back(t_micro_unordered_set);
    g_stock_micro_tree_set.push_back(t_micro_tree_set);
    g_stock_micro_vector_set.push_back(t_micro_vector_set);
    g_stock_micro_array_set.push_back(t_micro_array_set);
  }
}

void test_propagate_micro_inner_set()
{
  milliseconds start = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch());

  for(int zz = 0; zz < ITERATION; zz++)
  {
    g_list_micro_inner_set = vector<micro_inner_set<int>* >();

    for (int i = 0; i < LIST_SIZE; i++)
      g_list_micro_inner_set.push_back(new micro_inner_set<int>());

      for (int i = 0; i < COUNT_TIRAGE; i++)
      {
        int t_index = g_random_index_list[zz][i];

        micro_inner_set<int>* increment = g_stock_micro_inner_set.at(g_random_index_stock[zz][i]);

        //for (int j = t_index; j < LIST_SIZE; j++)
          //increment = g_list_micro_inner_set.at(j)->add_all_and_propagate(*increment);
      }
    }

  milliseconds end = duration_cast< milliseconds >(
  system_clock::now().time_since_epoch());

  milliseconds temps = end - start;

  cout << "micro_inner_set     : " << temps.count() << endl;
 }

 void test_propagate_micro_unordored_set()
 {
   milliseconds start = duration_cast< milliseconds >(
     system_clock::now().time_since_epoch());

   for(int zz = 0; zz < ITERATION; zz++)
   {
     g_list_micro_unordored_set = vector<micro_unordered_set<int>* >();

     for (int i = 0; i < LIST_SIZE; i++)
       g_list_micro_unordored_set.push_back(new micro_unordered_set<int>());


       for (int i = 0; i < COUNT_TIRAGE; i++)
       {
         int t_index = g_random_index_list[zz][i];

         micro_unordered_set<int>* increment = g_stock_micro_unordored_set.at(g_random_index_stock[zz][i]);

         for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
           increment = g_list_micro_unordored_set.at(j)->add_all_and_propagate(*increment);
       }
     }

   milliseconds end = duration_cast< milliseconds >(
   system_clock::now().time_since_epoch());

   milliseconds temps = end - start;

   cout << "micro_unordered_set : " << temps.count() << endl;
  }

  void test_propagate_micro_tree_set()
  {
    milliseconds start = duration_cast< milliseconds >(
      system_clock::now().time_since_epoch());

    for(int zz = 0; zz < ITERATION; zz++)
    {
      g_list_micro_tree_set = vector<micro_tree_set<int>* >();

      for (int i = 0; i < LIST_SIZE; i++)
        g_list_micro_tree_set.push_back(new micro_tree_set<int>());


        for (int i = 0; i < COUNT_TIRAGE; i++)
        {
          int t_index = g_random_index_list[zz][i];

          micro_tree_set<int>* increment = g_stock_micro_tree_set.at(g_random_index_stock[zz][i]);

          for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
            increment = g_list_micro_tree_set.at(j)->add_all_and_propagate(*increment);
        }
      }

    milliseconds end = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch());

    milliseconds temps = end - start;

    cout << "micro_tree_set      : " << temps.count() << endl;
 }

 void test_propagate_micro_vector_set()
 {
   milliseconds start = duration_cast< milliseconds >(
     system_clock::now().time_since_epoch());

   for(int zz = 0; zz < ITERATION; zz++)
   {
     g_list_micro_vector_set = vector<micro_vector_set<int>* >();

     for (int i = 0; i < LIST_SIZE; i++)
       g_list_micro_vector_set.push_back(new micro_vector_set<int>());


       for (int i = 0; i < COUNT_TIRAGE; i++)
       {
         int t_index = g_random_index_list[zz][i];

         micro_vector_set<int>* increment = g_stock_micro_vector_set.at(g_random_index_stock[zz][i]);

         for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
           increment = g_list_micro_vector_set.at(j)->add_all_and_propagate(*increment);
       }
     }

   milliseconds end = duration_cast< milliseconds >(
   system_clock::now().time_since_epoch());

   milliseconds temps = end - start;

   cout << "micro_vector_set    : " << temps.count() << endl;
}

void test_propagate_micro_array_set()
{
  milliseconds start = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch());

  for(int zz = 0; zz < ITERATION; zz++)
  {
    g_list_micro_array_set = vector<micro_array_set<int>* >();

    for (int i = 0; i < LIST_SIZE; i++)
      g_list_micro_array_set.push_back(new micro_array_set<int>());


      for (int i = 0; i < COUNT_TIRAGE; i++)
      {
        int t_index = g_random_index_list[zz][i];

        micro_array_set<int>* increment = g_stock_micro_array_set.at(g_random_index_stock[zz][i]);

        for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
          increment = g_list_micro_array_set.at(j)->add_all_and_propagate(*increment);
      }
    }

  milliseconds end = duration_cast< milliseconds >(
  system_clock::now().time_since_epoch());

  milliseconds temps = end - start;

  cout << "micro_array_set     : " << temps.count() << endl;
}


int main()
{
  init();

  test_propagate_micro_inner_set();
  test_propagate_micro_unordored_set();
  test_propagate_micro_tree_set();
  test_propagate_micro_vector_set();
  test_propagate_micro_array_set();
}
