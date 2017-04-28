#ifndef MICRO_SET_HPP
#define MICRO_SET_HPP

#include "inner_set.hpp"
#include "inner_set_0.hpp"

#include "iterator_inner_set.hpp"

using namespace std;

template<typename T>
class micro_set
{
    public :
      inner_set<T>* a_inner_set;

      micro_set();

      virtual ~micro_set();

      virtual iterator_inner_set<T> begin();

      virtual iterator_inner_set<T> end();

      virtual iterator_inner_set<T> find(T);

      virtual bool empty() const;

      virtual int size() const;

      virtual int max_size() const;

      virtual void insert(T);

      virtual void erase(T);

      virtual void clear();

      virtual bool retain_all(micro_set<T>);

      virtual void add_all(micro_set<T>);

      virtual void remove_all(micro_set<T>);

      virtual micro_set<T>* add_all_and_propagate(micro_set<T>);
};

#endif
