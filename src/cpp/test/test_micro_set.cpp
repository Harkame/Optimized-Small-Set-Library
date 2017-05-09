#include "test_micro_set.hpp"
#include <typeinfo>
#define G_NUMBER_ELEMENT 500
#define G_SIZE_ARRAY 100

int g_array_random_insert_1[G_SIZE_ARRAY];
int g_array_random_insert_2[G_SIZE_ARRAY];
int g_array_random_erase[G_SIZE_ARRAY];

int generate_random()
{
  srand( (unsigned) time(nullptr));

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
  {
    g_array_random_insert_1[t_index] = (rand() % G_NUMBER_ELEMENT) + 1;
    g_array_random_insert_2[t_index] = (rand() % G_NUMBER_ELEMENT) + 1;
  }

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    g_array_random_erase[t_index] = (rand() % G_NUMBER_ELEMENT) + 1;

}

CPPUNIT_TEST_SUITE_REGISTRATION( test_micro_set );

void test_micro_set::test_insert()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_micro_set<int>  t_iterator_micro_set;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
  {
    t_iterator_micro_set = t_micro_inner_set.find(g_array_random_insert_1[t_index]);

    CPPUNIT_ASSERT(*t_iterator_micro_set == g_array_random_insert_1[t_index]);
    CPPUNIT_ASSERT(t_iterator_micro_set != t_micro_inner_set.end());
  }

}

void test_micro_set::test_add_all()
{
  micro_inner_set<int> t_micro_inner_set_a;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set_a.insert(g_array_random_insert_1[t_index]);

  micro_inner_set<int> t_micro_inner_set_b;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set_b.insert(g_array_random_insert_2[t_index]);

  t_micro_inner_set_a.add_all(t_micro_inner_set_b);

  iterator_micro_set<int> t_iterator_micro_set_b = t_micro_inner_set_b.begin();

  while(t_iterator_micro_set_b != t_iterator_micro_set_b.end())
    CPPUNIT_ASSERT(t_micro_inner_set_a.find(*t_iterator_micro_set_b++) != t_micro_inner_set_a.end());
}

void test_micro_set::test_erase()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_micro_set<int>  t_iterator_micro_set;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.erase(g_array_random_erase[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(t_micro_inner_set.find(g_array_random_erase[t_index]) == t_micro_inner_set.end());
}

void test_micro_set::test_erase_all()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_micro_set<int>  t_iterator_micro_set;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.erase(g_array_random_insert_1[t_index]);

  CPPUNIT_ASSERT(t_micro_inner_set.size() == 0);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(t_micro_inner_set.find(g_array_random_erase[t_index]) == t_micro_inner_set.end());
}

void test_micro_set::test_retain_all()
{

}
void test_micro_set::test_find()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_micro_set<int>  t_iterator_micro_set;

  int t_count_insert = 0;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(*t_micro_inner_set.find(g_array_random_insert_1[t_index]) == g_array_random_insert_1[t_index]);
}

void test_micro_set::test_propagate()
{
//TODO
}

int main()
{
  generate_random();

  test_micro_set t_test_micro_set;

  t_test_micro_set.test_insert();

  t_test_micro_set.test_add_all();

  t_test_micro_set.test_erase();

  t_test_micro_set.test_erase_all();

  t_test_micro_set.test_retain_all();

  t_test_micro_set.test_find();

    t_test_micro_set.test_propagate();
}
