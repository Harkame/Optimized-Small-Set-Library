#include "iterator_inner_set.hpp"

template<typename T>
iterator_inner_set<T>::iterator_inner_set(inner_set<T>* p_inner_set)
{
  a_index = 0;

  a_inner_set = p_inner_set;
}

template<typename T>
iterator_inner_set<T>::~iterator_inner_set()
{

}

template<typename T>
void iterator_inner_set<T>::set_end()
{
  a_index = a_inner_set->get_size();
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::begin()
{
    a_index = 0;

    return *this;
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::end()
{
  a_index = a_inner_set->get_size();;

    return *this;
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::prev()
{
  if(a_index > 0)
    a_index--;

    return *this;
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::next()
{
  if(a_index < a_inner_set->get_size())
    a_index++;

    return *this;
}

template<typename T>
bool operator==(const iterator_inner_set<T> p_iterator_inner_set_a, const iterator_inner_set<T> p_iterator_inner_set_b)
{
  return p_iterator_inner_set_a.a_index == p_iterator_inner_set_b.a_index;
}

template<typename T>
bool operator!=(const iterator_inner_set<T> p_iterator_inner_set_a, const iterator_inner_set<T> p_iterator_inner_set_b)
{
  return p_iterator_inner_set_a.a_index != p_iterator_inner_set_b.a_index;
}

template<typename T>
T operator*(const iterator_inner_set<T> p_iterator_inner_set)
{
  return p_iterator_inner_set.a_inner_set->get_element(p_iterator_inner_set.a_index);
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::operator++()
{
   return next();
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::operator++(int)
{
  return operator++();
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::operator--()
{
  return prev();
}

template<typename T>
iterator_inner_set<T> iterator_inner_set<T>::operator--(int)
{
  return operator--();
}
