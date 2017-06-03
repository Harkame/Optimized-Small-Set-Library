#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

int main()
{
     unordered_set<int> v;

     v.insert(1);
          v.insert(2);

     cout << *v.begin() << endl;
     cout << *v.end() << endl;



     return 42;
}
