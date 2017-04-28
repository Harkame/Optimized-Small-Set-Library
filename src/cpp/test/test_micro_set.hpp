#ifndef TEST_MICRO_SET_HPP
#define TEST_MICRO_SET_HPP

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "inner_set.cpp"
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
#include "micro_unordered_set.cpp"
#include "micro_tree_set.cpp"
#include "micro_vector_set.cpp"

#include "iterator_inner_set.cpp"

class test_micro_set : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(test_micro_set);
  CPPUNIT_TEST_SUITE_END();

private:
  micro_set<int>* a_micro_set;

public:
  void test_insert();

  void test_erase();

  void test_retain_all();

  void test_begin();

  void test_end();

  void test_find();
};

#endif
