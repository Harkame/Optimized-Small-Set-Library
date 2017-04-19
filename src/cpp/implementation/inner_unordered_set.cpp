#include "inner_unordered_set.hpp"

template<typename T>
inner_unordered_set<T>::inner_unordered_set()
{
  a_values = new unordered_set<T>();
}

template<typename T>
inner_unordered_set<T>::inner_unordered_set(inner_array_set<T>* p_inner_set, T p_element)
{
  a_values = new unordered_set<T>();

  a_values->insert(p_inner_set->a_values[0]);
  a_values->insert(p_inner_set->a_values[1]);
  a_values->insert(p_inner_set->a_values[2]);
  a_values->insert(p_inner_set->a_values[3]);
  a_values->insert(p_inner_set->a_values[4]);
  a_values->insert(p_inner_set->a_values[5]);
  a_values->insert(p_inner_set->a_values[6]);
  a_values->insert(p_inner_set->a_values[7]);
  a_values->insert(p_inner_set->a_values[8]);
  a_values->insert(p_inner_set->a_values[9]);
  a_values->insert(p_inner_set->a_values[10]);
  a_values->insert(p_inner_set->a_values[11]);
  a_values->insert(p_inner_set->a_values[12]);
  a_values->insert(p_inner_set->a_values[13]);
  a_values->insert(p_inner_set->a_values[14]);
  a_values->insert(p_inner_set->a_values[15]);
  a_values->insert(p_inner_set->a_values[16]);
  a_values->insert(p_inner_set->a_values[17]);
  a_values->insert(p_inner_set->a_values[18]);
  a_values->insert(p_inner_set->a_values[19]);

  a_values->insert(p_element);

  delete p_inner_set;
}

template<typename T>
inner_unordered_set<T>::~inner_unordered_set()
{

}

template<typename T>
inner_set<T>* inner_unordered_set<T>::add_element(T p_element)
{
    a_values->insert(p_element);

    return this;
}

template<typename T>
inner_set<T>* inner_unordered_set<T>::add_all_elements(inner_set<T>* p_inner_set)
{
  for(auto t_iterator = a_values->begin(); t_iterator != a_values->end(); t_iterator++)
    p_inner_set->add_element(*t_iterator);

    return p_inner_set;
}

template<typename T>
bool inner_unordered_set<T>::contains_element(T p_element)
{
  auto t_iterator = a_values->begin();

  return t_iterator != a_values->end();
}

template<typename T>
bool inner_unordered_set<T>::contains_all_elements(inner_set<T>* p_inner_set)
{
    for(auto t_iterator = a_values->begin(); t_iterator != a_values->end(); t_iterator++)
      if(!p_inner_set->contains_element(*t_iterator))
      return false;

  return true;
}

template<typename T>
T inner_unordered_set<T>::get_element(int p_index)
{
  auto t_iterator = a_values->begin();

  std::advance(t_iterator, p_index);

  return *t_iterator;
}

template<typename T>
inner_set<T>* inner_unordered_set<T>::remove_element(T p_element)
{
  a_values->erase(p_element);

  return this;
}

template<typename T>
inner_set<T>* inner_unordered_set<T>::remove_all_elements(inner_set<T>* p_inner_set)
{
  for(auto t_iterator = a_values->begin(); t_iterator != a_values->end(); t_iterator++)
    p_inner_set->remove_element(*t_iterator);

    return p_inner_set;
}

template<typename T>
inner_set<T>* inner_unordered_set<T>::retain_all_element(inner_set<T>* p_inner_set)
{
  return p_inner_set;
}

template<typename T>
int inner_unordered_set<T>::get_size()
{
    return a_values->size();
}
