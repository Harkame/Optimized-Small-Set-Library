#include "iterator_micro_set.hpp"

template<typename T>
iterator_micro_set<T>::iterator_micro_set()
{
  a_index = 0;
}

template<typename T>
iterator_micro_set<T>::iterator_micro_set(inner_set<T>* p_inner_set)
{
  a_index = 0;

  a_inner_set = p_inner_set;
}

template<typename T>
iterator_micro_set<T>::~iterator_micro_set()
{

}

template<typename T>
void iterator_micro_set<T>::advance()
{
    a_index++;
}

template<typename T>
iterator_micro_set<T> iterator_micro_set<T>::begin()
{
    iterator_micro_set<T> r_iterator_micro_set(a_inner_set);

    r_iterator_micro_set.a_index = 0;

    return r_iterator_micro_set;
}

template<typename T>
iterator_micro_set<T> iterator_micro_set<T>::end()
{
  iterator_micro_set<T> r_iterator_micro_set(a_inner_set);

  r_iterator_micro_set.a_index = a_inner_set->get_size();

  return r_iterator_micro_set;
}

template<typename T>
iterator_micro_set<T> iterator_micro_set<T>::prev()
{
  if(a_index > 0)
  {
    a_index--;
  }

    return *this;
}

template<typename T>
iterator_micro_set<T> iterator_micro_set<T>::next()
{
  if(a_index < a_inner_set->get_size())
  {
    a_index++;
  }

    return *this;
}

template<typename T>
bool operator==(const iterator_micro_set<T> p_iterator_micro_set_1, const iterator_micro_set<T> p_iterator_micro_set_2)
{
  return p_iterator_micro_set_1.a_index == p_iterator_micro_set_2.a_index;
}

template<typename T>
bool operator!=(const iterator_micro_set<T> p_iterator_micro_set_1, const iterator_micro_set<T> p_iterator_micro_set_2)
{
  return p_iterator_micro_set_1.a_index != p_iterator_micro_set_2.a_index;
}

template<typename T>
T operator*(const iterator_micro_set<T> p_iterator_micro_set)
{
  return p_iterator_micro_set.a_inner_set->get_element(p_iterator_micro_set.a_index);
}

template<typename T>
iterator_micro_set<T>iterator_micro_set<T>::operator++()
{
  return next();
}

template<typename T>
iterator_micro_set<T>iterator_micro_set<T>::operator++(int)
{
  iterator_micro_set r_iterator_micro_set = *this;

  ++*this;

  return r_iterator_micro_set;
}

template<typename T>
iterator_micro_set<T> iterator_micro_set<T>::operator--()
{
  return prev();
}

template<typename T>
iterator_micro_set<T> iterator_micro_set<T>::operator--(int)
{
  iterator_micro_set r_iterator_micro_set = *this;

  --*this;

  return r_iterator_micro_set;
}
