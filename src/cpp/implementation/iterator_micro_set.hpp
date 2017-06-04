#ifndef ITERATOR_MICRO_SET_HPP
#define ITERATOR_MICRO_SET_HPP

#include "inner_set.hpp"

#include <iterator>

using namespace std;

template<typename T, int p_to_up>
class iterator_micro_set : virtual public iterator<bidirectional_iterator_tag, T>
{
  public:
    int a_index;
    inner_set<T, p_to_up>* a_inner_set;

    iterator_micro_set();

    iterator_micro_set(inner_set<T, p_to_up>*);

    virtual ~iterator_micro_set();

    virtual void advance();

    virtual iterator_micro_set<T, p_to_up> begin();

    virtual iterator_micro_set<T, p_to_up> end();

    virtual iterator_micro_set<T, p_to_up> prev();

    virtual iterator_micro_set<T, p_to_up> next();

    virtual iterator_micro_set<T, p_to_up> operator++();
    virtual iterator_micro_set<T, p_to_up> operator++(int);

    virtual iterator_micro_set<T, p_to_up> operator--();
    virtual iterator_micro_set<T, p_to_up> operator--(int);
};

#endif
