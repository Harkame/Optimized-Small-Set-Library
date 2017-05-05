#ifndef ITERATOR_MICRO_SET_HPP
#define ITERATOR_MICRO_SET_HPP

#include "inner_set.hpp"

#include <iterator>

using namespace std;

template<typename T>
class iterator_micro_set : virtual public iterator<bidirectional_iterator_tag, T>
{
  public:
    int a_index;
    inner_set<T>* a_inner_set;
    
    iterator_micro_set();

    iterator_micro_set(inner_set<T>*);

    virtual ~iterator_micro_set();

    virtual void advance();

    virtual iterator_micro_set<T> begin();

    virtual iterator_micro_set<T> end();

    virtual iterator_micro_set<T> prev();

    virtual iterator_micro_set<T> next();

    virtual iterator_micro_set<T> operator++();
    virtual iterator_micro_set<T> operator++(int);

    virtual iterator_micro_set<T> operator--();
    virtual iterator_micro_set<T> operator--(int);
};

#endif
