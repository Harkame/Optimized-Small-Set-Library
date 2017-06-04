#include <set>
#include <unordered_set>
#include <iostream>
#include "toto.hpp"

using namespace std;

template<typename T, int i>
void titi<T, i>::print()
{
     cout << "a_i = " << a_i << endl;
}



int main()
{
     titi<int, 785> t;
     t.print();

     return 42;
}
