#ifndef TEST_MICRO_SET_HPP
#define TEST_MICRO_SET_HPP

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "../implementation/inner_set.cpp"
#include "../implementation/inner_set_0.cpp"
#include "../implementation/inner_set_1.cpp"
#include "../implementation/inner_set_2.cpp"
#include "../implementation/inner_set_3.cpp"

#include "../implementation/inner_array_set.cpp"
#include "../implementation/inner_unordered_set.cpp"
#include "../implementation/inner_tree_set.cpp"

#include "../implementation/micro_set.cpp"

#include "../implementation/iterator_micro_set.cpp"


#define NUMBER_ITERATION 1000000
#define NUMBER_ELEMENT 75
#define SIZE_ARRAY 3
#define TO_UP 3

class test_micro_set : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(test_micro_set);
  CPPUNIT_TEST_SUITE_END();

  private:
    micro_set<int, TO_UP>* a_micro_set;

  public:
    /* Iterators */
    void test_begin();

    void test_end();

    void test_find();

    /* Capacity */
    void test_empty();

    void test_size();

    /* Modifiers */
    void test_insert();

    void test_insert_all();

    void test_erase();

    void test_erase_all();

    void test_retain_all();

    void test_clear();

    /* Custom */
    void test_add_all_and_propagate();
};

#endif
