#ifndef ITERATOR_INNER_SET_HPP
#define ITERATOR_INNER_SET_HPP

#include <iterator>

#include "inner_set.hpp"

using namespace std;

template<typename T>
class iterator_inner_set : virtual public iterator<bidirectional_iterator_tag, T>
{
  public:
    int a_index;

    inner_set<T>* a_inner_set;

    iterator_inner_set();

    iterator_inner_set(inner_set<T>*);

    virtual ~iterator_inner_set();

    void set_end();

    virtual iterator_inner_set<T> begin();

    virtual iterator_inner_set<T> end();

    virtual iterator_inner_set<T> prev();

    virtual iterator_inner_set<T> next();

    virtual iterator_inner_set<T> operator++();
    virtual iterator_inner_set<T> operator++(int);

    virtual iterator_inner_set<T> operator--();
    virtual iterator_inner_set<T> operator--(int);
};

#endif
