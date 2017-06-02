#ifndef TEST_ITERATOR_INNER_SET_HPP
#define TEST_ITERATOR_INNER_SET_HPP

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

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

#include "iterator_inner_set.cpp"

class test_iterator_inner_set : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(test_iterator_inner_set);
  CPPUNIT_TEST_SUITE_END();

private:
  micro_set<int>* a_micro_set;

public:
  void test_next();

  void test_prev();

  void test_begin();

  void test_end();
};

#endif
