#include "micro_set.hpp"
#include "micro_set.cpp"

int main()
{
  micro_set<int>* ms = new micro_set<int>();

  ms->insert(42);
}
