#ifndef INNER_SET_H
#define INNER_SET_H

#include <iterator>

using namespace std;

template<typename T>
class inner_set
{
    public :
      inner_set<T>(){}

      virtual ~inner_set<T>(){}

      virtual inner_set<T>* add_element(T*);

      virtual inner_set<T>* add_elements(T**);

      virtual bool contains_element(T*);

      virtual bool contains_all_elements(T*);

      virtual T* get_element(int);

      virtual inner_set<T>* remove_element(T*);

      virtual inner_set<T>* retain_all_element(T**);

      virtual  int get_size();
};


#endif
