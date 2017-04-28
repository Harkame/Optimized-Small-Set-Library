#include "test_micro_set.hpp"

#define G_NUMBER_ELEMENT 100
#define G_SIZE_ARRAY 7

int g_array_random_insert[G_SIZE_ARRAY];
int g_array_random_erase[G_SIZE_ARRAY];

int g_array_random_insert_random[G_SIZE_ARRAY];
int g_array_random_erase_random[G_SIZE_ARRAY];

int generate_random()
{
  srand( (unsigned) time(nullptr));

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    g_array_random_insert_random[t_index] = (rand() % G_NUMBER_ELEMENT) + 1;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    g_array_random_erase_random[t_index] = (rand() % G_NUMBER_ELEMENT) + 1;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
  {
    g_array_random_insert[t_index] = t_index;
    g_array_random_erase[t_index] = t_index;
  }
}

CPPUNIT_TEST_SUITE_REGISTRATION( test_micro_set );

void test_micro_set::test_insert()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_inner_set<int>  t_iterator_inner_set;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_random[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
  {
    t_iterator_inner_set = t_micro_inner_set.find(g_array_random_insert_random[t_index]);

    CPPUNIT_ASSERT(*t_iterator_inner_set == g_array_random_insert_random[t_index]);
    CPPUNIT_ASSERT(t_iterator_inner_set != t_micro_inner_set.end());
  }
}

void test_micro_set::test_erase()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_inner_set<int>  t_iterator_inner_set;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_random[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.erase(g_array_random_erase_random[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(t_micro_inner_set.find(g_array_random_erase_random[t_index]) == t_micro_inner_set.end());
}

void test_micro_set::test_retain_all()
{

}

void test_micro_set::test_begin()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_inner_set<int>  t_iterator_inner_set;

  int t_count_insert = 0;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_random[t_index]);

  CPPUNIT_ASSERT(*t_micro_inner_set.begin() == g_array_random_insert_random[0]);
}

void test_micro_set::test_end()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_inner_set<int>  t_iterator_inner_set;

  int t_count_insert = 0;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert[t_index]);

  CPPUNIT_ASSERT(*t_micro_inner_set.begin() == g_array_random_insert[G_SIZE_ARRAY]);
}

void test_micro_set::test_find()
{
  micro_inner_set<int> t_micro_inner_set;
  iterator_inner_set<int>  t_iterator_inner_set;

  int t_count_insert = 0;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_inner_set.insert(g_array_random_insert_random[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(*t_micro_inner_set.find(g_array_random_insert_random[t_index]) == g_array_random_insert_random[t_index]);
}


int main()
{
  generate_random();

  test_micro_set t_test_micro_set;

  t_test_micro_set.test_insert();

  t_test_micro_set.test_erase();

  t_test_micro_set.test_retain_all();

  t_test_micro_set.test_begin();

  t_test_micro_set.test_end();

  t_test_micro_set.test_find();
}
