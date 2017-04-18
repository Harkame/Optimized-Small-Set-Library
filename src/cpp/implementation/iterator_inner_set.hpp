#ifndef ITERATOR_INNER_SET_HPP
#define ITERATOR_INNER_SET_HPP

#include "inner_set.hpp"

using namespace std;

template<typename T>
class iterator_inner_set
{
  private:
    int a_index;

    inner_set<T>* a_inner_set;

  public:
    iterator_inner_set(inner_set<T>*);

    virtual ~iterator_inner_set();

    virtual T begin();

    virtual T end();

    virtual T prev();

    virtual T next();
};

#endif
