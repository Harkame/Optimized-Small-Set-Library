#include "test_iterator_inner_set.hpp"

#define G_NUMBER_ELEMENT 100
#define G_SIZE_ARRAY 7

int g_array_random_insert[G_SIZE_ARRAY];
int g_array_random_erase[G_SIZE_ARRAY];

int generate_random()
{
  srand( (unsigned) time(nullptr));

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    g_array_random_insert[t_index] = (rand() % G_NUMBER_ELEMENT) + 1;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    g_array_random_erase[t_index] = (rand() % G_NUMBER_ELEMENT) + 1;

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_iterator_inner_set );

void test_iterator_inner_set::test_next()
{
  micro_set<int> t_micro_set;
  iterator_inner_set<int>  t_iterator_inner_set;

  int t_count_insert = 0;

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert[t_index]);

  for(int t_index = 0; t_index < G_SIZE_ARRAY; t_index++)
  {
    CPPUNIT_ASSERT(*t_micro_set.find(g_array_random_insert[t_index]);

    CPPUNIT_ASSERT(*t_iterator_inner_set == g_array_random_insert[t_index]);
    CPPUNIT_ASSERT(t_iterator_inner_set != t_micro_set.end());
  }
}

int main()
{
  generate_random();

  test_iterator_inner_set t_test_iterator_inner_set;

  t_test_iterator_inner_set.test_next();

  t_test_iterator_inner_set.test_prev();

  t_test_iterator_inner_set.test_begin();

  t_test_iterator_inner_set.test_next();
}
