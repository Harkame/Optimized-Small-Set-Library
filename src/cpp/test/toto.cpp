#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int main()
{
     unordered_set<int> v;

     v.insert(42);

     bool b = v.begin() == v.end();

     bool t = true;

     cout << "t : " << t << endl;
     cout <<  b << endl;

     return 42;
}
