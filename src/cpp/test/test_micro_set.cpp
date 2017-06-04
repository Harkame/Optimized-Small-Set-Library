#include "test_micro_set.hpp"

int g_array_random_insert_1[SIZE_ARRAY];
int g_array_random_insert_2[SIZE_ARRAY];
int g_array_random_erase[SIZE_ARRAY];

void generate_random()
{
  srand( (unsigned) time(nullptr));

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
  {
    g_array_random_insert_1[t_index] = (rand() % NUMBER_ELEMENT) + 1;
    g_array_random_insert_2[t_index] = (rand() % NUMBER_ELEMENT) + 1;
  }

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    g_array_random_erase[t_index] = (rand() % NUMBER_ELEMENT) + 1;

}

CPPUNIT_TEST_SUITE_REGISTRATION( test_micro_set );

void test_micro_set::test_begin()
{
  if(SIZE_ARRAY > 20)
    return;

  micro_set<int, TO_UP> t_micro_set;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  CPPUNIT_ASSERT(*t_micro_set.begin() == g_array_random_insert_1[0]);
}

void test_micro_set::test_end()
{
  if(SIZE_ARRAY > 20)
    return;

  micro_set<int, TO_UP> t_micro_set;
  iterator_micro_set<int, TO_UP>  t_iterator_micro_set;

  t_iterator_micro_set = t_micro_set.end();

  CPPUNIT_ASSERT(t_iterator_micro_set == t_micro_set.begin());

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  t_iterator_micro_set = t_micro_set.end();

  CPPUNIT_ASSERT(t_iterator_micro_set == t_iterator_micro_set.end());
}

void test_micro_set::test_find()
{
  micro_set<int, TO_UP> t_micro_set;
  iterator_micro_set<int, TO_UP>  t_iterator_micro_set;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(t_micro_set.find(g_array_random_insert_1[t_index]) != t_micro_set.end());
}

void test_micro_set::test_empty()
{
  micro_set<int, TO_UP> t_micro_set;

  CPPUNIT_ASSERT(t_micro_set.empty());

  CPPUNIT_ASSERT(t_micro_set.size() == 0);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  t_micro_set.clear();

  CPPUNIT_ASSERT(t_micro_set.empty());

  CPPUNIT_ASSERT(t_micro_set.size() == 0);
}

void test_micro_set::test_size()
{
  micro_set<int, TO_UP> t_micro_set;

  CPPUNIT_ASSERT(t_micro_set.size() == 0);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  int t_count = 0;

  for(auto t_iterator = t_micro_set.begin(); t_iterator != t_micro_set.end(); t_iterator++)
    t_count++;

  CPPUNIT_ASSERT(t_count == t_micro_set.size());

  t_micro_set.clear();

  CPPUNIT_ASSERT(t_micro_set.size() == 0);
}

void test_micro_set::test_insert()
{
  micro_set<int, TO_UP> t_micro_set;
  iterator_micro_set<int, TO_UP>  t_iterator_micro_set;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
  {
    t_iterator_micro_set = t_micro_set.find(g_array_random_insert_1[t_index]);

    CPPUNIT_ASSERT(*t_iterator_micro_set == g_array_random_insert_1[t_index]);
    CPPUNIT_ASSERT(t_iterator_micro_set != t_micro_set.end());
  }

  for(t_iterator_micro_set = t_micro_set.begin(); t_iterator_micro_set != t_micro_set.end(); t_iterator_micro_set++)
  {
    int t_count_occurence = 0;
    iterator_micro_set<int, TO_UP> t_iterator_micro_set_2 = t_micro_set.begin();

    for(auto t_iterator_micro_set_2 = t_micro_set.begin(); t_iterator_micro_set_2 != t_micro_set.end(); t_iterator_micro_set_2++)
      if(*t_iterator_micro_set == *t_iterator_micro_set_2)
        t_count_occurence++;

    CPPUNIT_ASSERT(t_count_occurence == 1);
  }
}

void test_micro_set::test_insert_all()
{
  micro_set<int, TO_UP> t_micro_set_a;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set_a.insert(g_array_random_insert_1[t_index]);

  micro_set<int, TO_UP> t_micro_set_b;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set_b.insert(g_array_random_insert_2[t_index]);

  t_micro_set_a.insert_all(t_micro_set_b);

  for(auto t_iterator = t_micro_set_b.begin(); t_iterator != t_micro_set_b.end(); t_iterator++)
    CPPUNIT_ASSERT(t_micro_set_a.find(*t_iterator) != t_micro_set_a.end());

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(t_micro_set_a.find(g_array_random_insert_2[t_index]) != t_micro_set_a.end());
}

void test_micro_set::test_erase()
{
  micro_set<int, TO_UP> t_micro_set;
  iterator_micro_set<int, TO_UP>  t_iterator_micro_set;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.erase(g_array_random_erase[t_index]);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(t_micro_set.find(g_array_random_erase[t_index]) == t_micro_set.end());
}

void test_micro_set::test_erase_all()
{
  micro_set<int, TO_UP> t_micro_set;
  iterator_micro_set<int, TO_UP>  t_iterator_micro_set;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.erase(g_array_random_insert_1[t_index]);

  CPPUNIT_ASSERT(t_micro_set.size() == 0);

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    CPPUNIT_ASSERT(t_micro_set.find(g_array_random_erase[t_index]) == t_micro_set.end());
}

void test_micro_set::test_retain_all()
{
  micro_set<int, TO_UP> t_micro_set_a;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set_a.insert(g_array_random_insert_1[t_index]);

  micro_set<int, TO_UP> t_micro_set_b;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set_b.insert(g_array_random_insert_2[t_index]);

    for(auto t_iterator_set = t_micro_set_a.begin(); t_iterator_set != t_micro_set_a.end(); t_iterator_set++)
      cout << *t_iterator_set << endl;

      cout << "------------" << endl;
      for(auto t_iterator_set = t_micro_set_b.begin(); t_iterator_set != t_micro_set_b.end(); t_iterator_set++)
        cout << *t_iterator_set << endl;

  t_micro_set_a.retain_all(t_micro_set_b);

        cout << "------------" << endl;

  set<int> t_retain_values;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
      for(int t_index_2 = 0; t_index_2 < SIZE_ARRAY; t_index_2++)
        if(g_array_random_insert_1[t_index] == g_array_random_insert_2[t_index_2])
          t_retain_values.insert(g_array_random_insert_1[t_index]);

  for(auto t_iterator_set = t_micro_set_a.begin(); t_iterator_set != t_micro_set_a.end(); t_iterator_set++)
    cout << *t_iterator_set << endl;

  for(auto t_iterator_set = t_retain_values.begin(); t_iterator_set != t_retain_values.end(); t_iterator_set++)
    cout << *t_iterator_set << endl;

  CPPUNIT_ASSERT(t_micro_set_a.size() == t_retain_values.size());

  for(auto t_iterator_set = t_retain_values.begin(); t_iterator_set != t_retain_values.end(); t_iterator_set++)
  {
    CPPUNIT_ASSERT(t_micro_set_a.find(*t_iterator_set) != t_micro_set_a.end());
    CPPUNIT_ASSERT(t_retain_values.find(*t_iterator_set) != t_retain_values.end());
  }
}

void test_micro_set::test_clear()
{
  micro_set<int, TO_UP> t_micro_set;

  for(int t_index = 0; t_index < SIZE_ARRAY; t_index++)
    t_micro_set.insert(g_array_random_insert_1[t_index]);

  t_micro_set.clear();

  CPPUNIT_ASSERT(t_micro_set.size() == 0);
}

void test_micro_set::test_add_all_and_propagate()
{
//TODO
}

int main()
{
  int t_count_iteration = 0;

  while(t_count_iteration != NUMBER_ITERATION)
  {
    cout << endl << "--- ITERATION [" << t_count_iteration << "] ---" << endl;

    generate_random();

    test_micro_set t_test_micro_set;

    cout << "test_begin" << endl;

    t_test_micro_set.test_begin();

    cout << "test_begin                 [OK]" << endl;

    cout << "test_end" << endl;

    t_test_micro_set.test_end();

    cout << "test_end                   [OK]" << endl;

    cout << "test_find" << endl;

    t_test_micro_set.test_find();

    cout << "test_find                  [OK]" << endl;

    cout << "test_empty" << endl;

    t_test_micro_set.test_empty();

    cout << "test_empty                 [OK]" << endl;

    cout << "test_size" << endl;

    t_test_micro_set.test_size();

    cout << "test_size                  [OK]" << endl;

    cout << "test_insert" << endl;

    t_test_micro_set.test_insert();

    cout << "test_insert                [OK]" << endl;

    cout << "test_insert_all" << endl;

    t_test_micro_set.test_insert_all();

    cout << "test_insert_all            [OK]" << endl;

    cout << "test_erase" << endl;

    t_test_micro_set.test_erase();

    cout << "test_erase                 [OK]" << endl;

    cout << "test_erase_all" << endl;

    t_test_micro_set.test_erase_all();

    cout << "test_erase_all             [OK]" << endl;

    cout << "test_retain_all" << endl;

    t_test_micro_set.test_retain_all();

    cout << "test_retain_all            [OK]" << endl;

    cout << "test_clear" << endl;

    t_test_micro_set.test_clear();

    cout << "test_clear                 [OK]" << endl;

    cout << "test_add_all_and_propagate" << endl;

    t_test_micro_set.test_add_all_and_propagate();

    cout << "test_add_all_and_propagate [OK]" << endl;

    t_count_iteration++;
  }
}
