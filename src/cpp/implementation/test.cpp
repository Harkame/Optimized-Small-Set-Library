#include "inner_set.cpp"
#include "inner_set_0.cpp"
#include "inner_set_1.cpp"
#include "inner_set_2.cpp"
#include "inner_set_3.cpp"

#include "inner_array_set.cpp"
#include "micro_set.cpp"
#include "inner_tree_set.cpp"
#include "inner_unordered_set.cpp"
#include "iterator_micro_set.cpp"

int main()
{
  micro_set<int, 2> micro;

  micro.insert(42);
  micro.insert(44);
  micro.insert(43);
  micro.insert(4523);
  micro.insert(473);

  return 42;
}
