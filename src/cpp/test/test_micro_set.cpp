#include "test_micro_set.hpp"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION( test_micro_set );

void test_micro_set::test_insert()
{
  micro_set<int>* t_micro_set = new micro_set<int>();

  t_micro_set->insert(42);

  iterator_inner_set<int>* t_iterator_inner_set = t_micro_set->begin();

  CPPUNIT_ASSERT(t_iterator_inner_set->next() == 42);

  CPPUNIT_ASSERT(t_micro_set->size() == 1);

    t_micro_set->insert(96);

  t_iterator_inner_set = t_micro_set->begin();

  CPPUNIT_ASSERT(t_iterator_inner_set->next() == 42);
  CPPUNIT_ASSERT(t_iterator_inner_set->next() == 96);

  CPPUNIT_ASSERT(t_micro_set->size() == 2);
}

void test_micro_set::test_erase()
{
  micro_set<int>* t_micro_set = new micro_set<int>();

  iterator_inner_set<int>* t_iterator_inner_set = t_micro_set->begin();

  t_micro_set->insert(42);
  t_micro_set->insert(93);
  t_micro_set->insert(62);

  t_micro_set->erase(93);

  t_iterator_inner_set = t_micro_set->begin();

  CPPUNIT_ASSERT(t_iterator_inner_set->next() == 42);
  CPPUNIT_ASSERT(t_iterator_inner_set->next() == 62);

  CPPUNIT_ASSERT(t_micro_set->size() == 2);

}

int main()
{
  test_micro_set* t_test_micro_set = new test_micro_set();

  t_test_micro_set->test_insert();

  t_test_micro_set->test_erase();
}
