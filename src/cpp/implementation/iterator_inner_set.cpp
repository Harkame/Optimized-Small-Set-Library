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
T iterator_inner_set<T>::begin()
{
    a_index = 0;

  return a_inner_set->get_element(0);
}

template<typename T>
T iterator_inner_set<T>::end()
{
  a_index = a_inner_set->get_size();;

  return a_inner_set->get_element(a_inner_set->get_size());
}

template<typename T>
T iterator_inner_set<T>::prev()
{
  if(a_index > 0)
    a_index--;

  return a_inner_set->get_element(a_index - 1);
}

template<typename T>
T iterator_inner_set<T>::next()
{
  if(a_index < a_inner_set->get_size())
    a_index++;

  return a_inner_set->get_element(a_index - 1);
}
