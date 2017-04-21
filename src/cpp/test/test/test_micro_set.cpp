#include "test_micro_set.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION( test_micro_set );

void test_micro_set::test_insert()
{
  micro_set<int> t_micro_set;

  t_micro_set.insert(42);
  t_micro_set.insert(125);
  t_micro_set.insert(125);
  t_micro_set.insert(42);
  t_micro_set.insert(12);

  CPPUNIT_ASSERT(t_micro_set.size() == 3);

  iterator_inner_set<int> t_iterator = t_micro_set.begin();

  CPPUNIT_ASSERT(*t_iterator++== 42);
  CPPUNIT_ASSERT(*t_iterator++ == 125);
  CPPUNIT_ASSERT(*t_iterator++ == 12);
}

void test_micro_set::test_erase()
{
  micro_set<int> t_micro_set;

  t_micro_set.insert(42);
  t_micro_set.insert(125);
  t_micro_set.insert(12);

  iterator_inner_set<int> t_iterator = t_micro_set.begin();

  t_micro_set.erase(42);

  CPPUNIT_ASSERT(t_micro_set.size() == 2);

  t_iterator = t_micro_set.find(42);

  CPPUNIT_ASSERT(*t_iterator != 42);

  t_micro_set.erase(12);

  CPPUNIT_ASSERT(t_micro_set.size() == 1);

  t_iterator = t_micro_set.find(12);

  CPPUNIT_ASSERT(*t_iterator != 12);
}

void test_micro_set::test_retain_all()
{
  micro_set<int> t_micro_set_a;
  micro_set<int> t_micro_set_b;

  t_micro_set_a.insert(42);
  t_micro_set_a.insert(125);
  t_micro_set_a.insert(54);
  t_micro_set_a.insert(12);

  t_micro_set_b.insert(42);
  t_micro_set_b.insert(12);
  t_micro_set_b.insert(53);

  CPPUNIT_ASSERT(t_micro_set_a.retain_all(t_micro_set_b) == true);

  iterator_inner_set<int> t_iterator = t_micro_set_a.begin();

  CPPUNIT_ASSERT(t_micro_set_a.size() == 2);

  CPPUNIT_ASSERT(*t_iterator++ == 42);
  CPPUNIT_ASSERT(*t_iterator++ == 12);
}

void test_micro_set::test_iterator()
{
  micro_set<int> t_micro_set;

  t_micro_set.insert(42);
  t_micro_set.insert(125);
  t_micro_set.insert(54);
  t_micro_set.insert(12);

  iterator_inner_set<int> t_iterator = t_micro_set.begin();

  CPPUNIT_ASSERT(*t_iterator++ == 42);
  CPPUNIT_ASSERT(*t_iterator++ == 125);
  CPPUNIT_ASSERT(*t_iterator++ == 54);
  CPPUNIT_ASSERT(*t_iterator++ == 12);

  t_iterator = t_micro_set.end();

  CPPUNIT_ASSERT(*t_iterator == 12);
  CPPUNIT_ASSERT(*t_iterator-- == 54);

    t_iterator = t_micro_set.find(42);

    CPPUNIT_ASSERT(*t_iterator == 42);
}


int main()
{
  test_micro_set* t_test_micro_set = new test_micro_set();

  t_test_micro_set->test_insert();

  t_test_micro_set->test_erase();

  t_test_micro_set->test_retain_all();

  t_test_micro_set->test_iterator();
}
