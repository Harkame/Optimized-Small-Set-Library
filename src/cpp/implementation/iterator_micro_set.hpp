#ifndef ITERATOR_INNER_SET_HPP
#define ITERATOR_INNER_SET_HPP

#include "inner_set.hpp"

#include <iterator>

using namespace std;

template<typename T>
class iterator_inner_set
{
  private:
    inner_set<T>* a_inner_set;

  public:
    iterator_micro_set(inner_set<T>*, bool);

    virtual ~iterator_micro_set();

    virtual void advance();

    virtual void distance();

    virtual void begin();

    virtual void end();

    virtual void prev();

    virtual void next();
}

#endif
