#ifndef MICRO_INNER_SET_HPP
#define MICRO_INNER_SET_HPP

#include "inner_set.hpp"
#include "inner_set_0.hpp"

#include "iterator_micro_set.hpp"

using namespace std;

template<typename T>
class micro_inner_set : virtual public micro_set<T>
{
    public :
      micro_inner_set();

      virtual ~micro_inner_set();

      /* Iterators */
      virtual iterator_micro_set<T> begin() const;

      virtual iterator_micro_set<T> end() const;

      virtual iterator_micro_set<T> find(T) const;

      /* Capacity */
      virtual bool empty() const;

      virtual int size() const;

      /* Modifiers */
      virtual void insert(T);

      virtual void insert_all(micro_set<T>);

      virtual void erase(T);

      virtual void erase_all(micro_set<T>);

      virtual bool retain_all(micro_set<T>);

      virtual void clear();

      /* Custom */
      virtual micro_set<T>* add_all_and_propagate(micro_set<T>);
  };

#endif
