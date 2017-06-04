#include "iterator_micro_set.hpp"

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up>::iterator_micro_set()
{
  a_index = 0;
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up>::iterator_micro_set(inner_set<T, p_to_up>* p_inner_set)
{
  a_index = 0;

  a_inner_set = p_inner_set;
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up>::~iterator_micro_set()
{

}

template<typename T, int p_to_up>
void iterator_micro_set<T, p_to_up>::advance()
{
    a_index++;
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> iterator_micro_set<T, p_to_up>::begin()
{
    iterator_micro_set<T, p_to_up> r_iterator_micro_set(a_inner_set);

    r_iterator_micro_set.a_index = 0;

    return r_iterator_micro_set;
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> iterator_micro_set<T, p_to_up>::end()
{
  iterator_micro_set<T, p_to_up> r_iterator_micro_set(a_inner_set);

  r_iterator_micro_set.a_index = a_inner_set->get_size();

  return r_iterator_micro_set;
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> iterator_micro_set<T, p_to_up>::prev()
{
  if(a_index > 0)
  {
    a_index--;
  }

    return *this;
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> iterator_micro_set<T, p_to_up>::next()
{
  if(a_index < a_inner_set->get_size())
  {
    a_index++;
  }

    return *this;
}

template<typename T, int p_to_up>
bool operator==(const iterator_micro_set<T, p_to_up> p_iterator_micro_set_1, const iterator_micro_set<T, p_to_up> p_iterator_micro_set_2)
{
  return p_iterator_micro_set_1.a_index == p_iterator_micro_set_2.a_index;
}

template<typename T, int p_to_up>
bool operator!=(const iterator_micro_set<T, p_to_up> p_iterator_micro_set_1, const iterator_micro_set<T, p_to_up> p_iterator_micro_set_2)
{
  return p_iterator_micro_set_1.a_index != p_iterator_micro_set_2.a_index;
}

template<typename T, int p_to_up>
T operator*(const iterator_micro_set<T, p_to_up> p_iterator_micro_set)
{
  return p_iterator_micro_set.a_inner_set->get_element(p_iterator_micro_set.a_index);
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up>iterator_micro_set<T, p_to_up>::operator++()
{
  return next();
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up>iterator_micro_set<T, p_to_up>::operator++(int)
{
  iterator_micro_set r_iterator_micro_set = *this;

  ++*this;

  return r_iterator_micro_set;
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> iterator_micro_set<T, p_to_up>::operator--()
{
  return prev();
}

template<typename T, int p_to_up>
iterator_micro_set<T, p_to_up> iterator_micro_set<T, p_to_up>::operator--(int)
{
  iterator_micro_set r_iterator_micro_set = *this;

  --*this;

  return r_iterator_micro_set;
}
