#ifndef MICRO_ARRAY_SET_HPP
#define MICRO_ARRAY_SET_HPP

#include "inner_set.hpp"
#include "inner_set_0.hpp"

#include "iterator_micro_set.hpp"

using namespace std;

template<typename T>
class micro_array_set : virtual public micro_set<T>
{
    public :
      micro_array_set();

      virtual ~micro_array_set();

      virtual iterator_micro_set<T> begin();

      virtual iterator_micro_set<T> end();

      virtual iterator_micro_set<T> find(T);

      virtual bool empty() const;

      virtual int size() const;

      virtual int max_size() const;

      virtual void insert(T);

      virtual void erase(T);

      virtual void clear();

      virtual bool retain_all(micro_array_set<T>);

      virtual void add_all(micro_array_set<T>);

      virtual void remove_all(micro_array_set<T>);

      virtual micro_array_set<T>* add_all_and_propagate(micro_array_set<T>);
  };

#endif