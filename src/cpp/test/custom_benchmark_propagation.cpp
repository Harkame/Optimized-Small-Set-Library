#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <vector>

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

 //#define MEGABYTE 1024L * 1024L
 #define POOL_SIZE          30
 #define STOCK_SIZE        20
 #define LIST_SIZE             50
 #define COUNT_TIRAGE  10
 #define ITERATION          5000
 #define TO_UP 10

 using namespace std;
 using namespace std::chrono;

vector<int> test_object;

vector<micro_set<int, TO_UP>* > g_stock_micro_set;
vector<micro_set<int, TO_UP>* > g_list_micro_set;

vector<micro_array_set<int, TO_UP>* > g_stock_micro_array_set;
vector<micro_array_set<int, TO_UP>* > g_list_micro_array_set;


vector<micro_unordered_set<int, TO_UP>* > g_stock_micro_unordored_set;
vector<micro_unordered_set<int, TO_UP>* > g_list_micro_unordored_set;

vector<micro_tree_set<int, TO_UP>* > g_stock_micro_tree_set;
vector<micro_tree_set<int, TO_UP>* > g_list_micro_tree_set;

vector<micro_vector_set<int, TO_UP>* > g_stock_micro_vector_set;
vector<micro_vector_set<int, TO_UP>* > g_list_micro_vector_set;

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
    micro_set<int, TO_UP>*           t_micro_set                                 = new micro_set<int, TO_UP>();
    micro_array_set<int, TO_UP>*           t_micro_array_set           = new micro_array_set<int, TO_UP>();
    micro_tree_set<int, TO_UP>*             t_micro_tree_set             = new micro_tree_set<int, TO_UP>();
    micro_unordered_set<int, TO_UP>* t_micro_unordered_set = new micro_unordered_set<int, TO_UP>();
    micro_vector_set<int, TO_UP>*         t_micro_vector_set      =   new micro_vector_set<int, TO_UP>();


    for (int j = 0; j < g_count_object[i]; j++)
    {
      int t_random = rand() % POOL_SIZE;

      t_micro_set->insert(test_object.at(t_random));
      t_micro_array_set->insert(test_object.at(t_random));
      t_micro_tree_set->insert(test_object.at(t_random));
      t_micro_unordered_set->insert(test_object.at(t_random));
      t_micro_vector_set->insert(test_object.at(t_random));
    }

    g_stock_micro_set.push_back(t_micro_set);
    g_stock_micro_array_set.push_back(t_micro_array_set);
    g_stock_micro_tree_set.push_back(t_micro_tree_set);
    g_stock_micro_unordored_set.push_back(t_micro_unordered_set);
    g_stock_micro_vector_set.push_back(t_micro_vector_set);
  }
}

void test_propagate_micro_set()
{
  milliseconds start = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch());

  for(int zz = 0; zz < ITERATION; zz++)
  {
    g_list_micro_set = vector<micro_set<int, TO_UP>* >();

    for (int i = 0; i < LIST_SIZE; i++)
      g_list_micro_set.push_back(new micro_set<int, TO_UP>());

      for (int i = 0; i < COUNT_TIRAGE; i++)
      {
        int t_index = g_random_index_list[zz][i];

        micro_set<int, TO_UP>* increment = g_stock_micro_set.at(g_random_index_stock[zz][i]);

        for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
          increment = g_list_micro_set.at(j)->add_all_and_propagate(*increment);
      }
    }

  milliseconds end = duration_cast< milliseconds >(
  system_clock::now().time_since_epoch());

  milliseconds temps = end - start;

  cout << "micro_set     : " << temps.count() << endl;
 }

 void test_propagate_micro_array_set()
 {
   milliseconds start = duration_cast< milliseconds >(
     system_clock::now().time_since_epoch());

   for(int zz = 0; zz < ITERATION; zz++)
   {
     g_list_micro_array_set = vector<micro_array_set<int, TO_UP>* >();

     for (int i = 0; i < LIST_SIZE; i++)
       g_list_micro_array_set.push_back(new micro_array_set<int, TO_UP>());


       for (int i = 0; i < COUNT_TIRAGE; i++)
       {
         int t_index = g_random_index_list[zz][i];

         micro_array_set<int, TO_UP>* increment = g_stock_micro_array_set.at(g_random_index_stock[zz][i]);

         for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
           increment = g_list_micro_array_set.at(j)->add_all_and_propagate(*increment);
       }
     }

   milliseconds end = duration_cast< milliseconds >(
   system_clock::now().time_since_epoch());

   milliseconds temps = end - start;

   cout << "micro_array_set     : " << temps.count() << endl;
 }

 void test_propagate_micro_tree_set()
 {
   milliseconds start = duration_cast< milliseconds >(
     system_clock::now().time_since_epoch());

   for(int zz = 0; zz < ITERATION; zz++)
   {
     g_list_micro_tree_set = vector<micro_tree_set<int, TO_UP>* >();

     for (int i = 0; i < LIST_SIZE; i++)
       g_list_micro_tree_set.push_back(new micro_tree_set<int, TO_UP>());


       for (int i = 0; i < COUNT_TIRAGE; i++)
       {
         int t_index = g_random_index_list[zz][i];

         micro_tree_set<int, TO_UP>* increment = g_stock_micro_tree_set.at(g_random_index_stock[zz][i]);

         for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
           increment = g_list_micro_tree_set.at(j)->add_all_and_propagate(*increment);
       }
     }

   milliseconds end = duration_cast< milliseconds >(
   system_clock::now().time_since_epoch());

   milliseconds temps = end - start;

   cout << "micro_tree_set      : " << temps.count() << endl;
}

 void test_propagate_micro_unordored_set()
 {
   milliseconds start = duration_cast< milliseconds >(
     system_clock::now().time_since_epoch());

   for(int zz = 0; zz < ITERATION; zz++)
   {
     g_list_micro_unordored_set = vector<micro_unordered_set<int, TO_UP>* >();

     for (int i = 0; i < LIST_SIZE; i++)
       g_list_micro_unordored_set.push_back(new micro_unordered_set<int, TO_UP>());


       for (int i = 0; i < COUNT_TIRAGE; i++)
       {
         int t_index = g_random_index_list[zz][i];

         micro_unordered_set<int, TO_UP>* increment = g_stock_micro_unordored_set.at(g_random_index_stock[zz][i]);

         for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
           increment = g_list_micro_unordored_set.at(j)->add_all_and_propagate(*increment);
       }
     }

   milliseconds end = duration_cast< milliseconds >(
   system_clock::now().time_since_epoch());

   milliseconds temps = end - start;

   cout << "micro_unordered_set : " << temps.count() << endl;
  }

  void test_propagate_micro_vector_set()
  {
    milliseconds start = duration_cast< milliseconds >(
      system_clock::now().time_since_epoch());

    for(int zz = 0; zz < ITERATION; zz++)
    {
      g_list_micro_vector_set = vector<micro_vector_set<int, TO_UP>* >();

      for (int i = 0; i < LIST_SIZE; i++)
        g_list_micro_vector_set.push_back(new micro_vector_set<int, TO_UP>());


        for (int i = 0; i < COUNT_TIRAGE; i++)
        {
          int t_index = g_random_index_list[zz][i];

          micro_vector_set<int, TO_UP>* increment = g_stock_micro_vector_set.at(g_random_index_stock[zz][i]);

          for (int j = t_index; j < LIST_SIZE && !increment->empty(); j++)
            increment = g_list_micro_vector_set.at(j)->add_all_and_propagate(*increment);
        }
      }

    milliseconds end = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch());

    milliseconds temps = end - start;

    cout << "micro_vector_set : " << temps.count() << endl;
   }

int main()
{
  init();

  test_propagate_micro_set();
  test_propagate_micro_array_set();
  test_propagate_micro_tree_set();
  test_propagate_micro_unordored_set();
  test_propagate_micro_vector_set();
}
