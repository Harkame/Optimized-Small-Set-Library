#include "inner_set_0.hpp"
#include "inner_array_set.hpp"

#include "inner_tree_set.hpp"
#include "iterator_micro_set.hpp"

template<typename T, int p_to_up>
inner_array_set<T, p_to_up>::inner_array_set()
{
  a_index = 0;
}

template<typename T, int p_to_up>
inner_array_set<T, p_to_up>::inner_array_set(T p_element)
{
  a_index = 1;

  a_values[0] = p_element;
}

template<typename T, int p_to_up>
inner_array_set<T, p_to_up>::inner_array_set(inner_set_1<T, p_to_up>* p_inner_set, T p_element)
{
  a_index = 2;

  a_values[0] = p_inner_set->a_values.element_1;

  a_values[1] = p_element;

  delete p_inner_set;
}

template<typename T, int p_to_up>
inner_array_set<T, p_to_up>::inner_array_set(inner_set_2<T, p_to_up>* p_inner_set, T p_element)
{
  a_index = 3;

  a_values[0] = p_inner_set->a_values.element_1;
  a_values[1] = p_inner_set->a_values.element_2;

  a_values[2] = p_element;

  delete p_inner_set;
}

template<typename T, int p_to_up>
inner_array_set<T, p_to_up>::inner_array_set(inner_set_3<T, p_to_up>* p_inner_set, T p_element)
{
  a_index = 4;

  a_values[0] = p_inner_set->a_values.element_1;
  a_values[1] = p_inner_set->a_values.element_2;
  a_values[2] = p_inner_set->a_values.element_3;

  a_values[3] = p_element;

  delete p_inner_set;
}

template<typename T, int p_to_up>
inner_array_set<T, p_to_up>::inner_array_set(inner_set<T, p_to_up>* p_inner_set)
{
  a_index = 0;

  iterator_micro_set<T, p_to_up> t_iterator(p_inner_set);
  for(t_iterator = t_iterator; t_iterator != t_iterator.end(); t_iterator++)
    this->a_values[a_index++] = *t_iterator;
}

template<typename T, int p_to_up>
inner_array_set<T, p_to_up>::~inner_array_set()
{

}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::add_element(T p_element)
{
  if(!contains_element(p_element))
  {
    if(a_index == 20)
    {
        return new inner_tree_set<T, p_to_up>(this, p_element);
    }
    else
    {
        a_values[a_index++] = p_element;
      }
    }

  return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::add_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  /*
  if((this->get_size() + p_inner_set->get_size()) > 20)
  {
    p_inner_set = new inner_tree_set<T>(p_inner_set);
    p_inner_set->add_all_elements(this);
  }
  else
  {
    iterator_micro_set<T, p_to_up> t_iterator(this);
    for(t_iterator; t_iterator != t_iterator.end(); t_iterator++)
      p_inner_set = p_inner_set->add_element(*t_iterator);
  }
  */

  iterator_micro_set<T, p_to_up> t_iterator(this);
  for(t_iterator; t_iterator != t_iterator.end(); t_iterator++)
    p_inner_set = p_inner_set->add_element(*t_iterator);

  return p_inner_set;
}

template<typename T, int p_to_up>
bool inner_array_set<T, p_to_up>::contains_element(T p_element)
{
  for(int t_index = 0; t_index < a_index; t_index++)
    if(a_values[t_index] == p_element)
      return true;

  return false;
}

template<typename T, int p_to_up>
bool inner_array_set<T, p_to_up>::contains_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->contains_element(a_values[0]) &&
  p_inner_set->contains_element(a_values[1])   &&
  p_inner_set->contains_element(a_values[2])   &&
  p_inner_set->contains_element(a_values[3])   &&
  p_inner_set->contains_element(a_values[4])   &&
  p_inner_set->contains_element(a_values[5])   &&
  p_inner_set->contains_element(a_values[6])   &&
  p_inner_set->contains_element(a_values[7])   &&
  p_inner_set->contains_element(a_values[8])   &&
  p_inner_set->contains_element(a_values[9])   &&
  p_inner_set->contains_element(a_values[10]) &&
  p_inner_set->contains_element(a_values[11]) &&
  p_inner_set->contains_element(a_values[12]) &&
  p_inner_set->contains_element(a_values[13]) &&
  p_inner_set->contains_element(a_values[14]) &&
  p_inner_set->contains_element(a_values[15]) &&
  p_inner_set->contains_element(a_values[16]) &&
  p_inner_set->contains_element(a_values[17]) &&
  p_inner_set->contains_element(a_values[18]) &&
  p_inner_set->contains_element(a_values[19]);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::copy()
{
  return new inner_array_set<T, p_to_up>(this);
}

template<typename T, int p_to_up>
T inner_array_set<T, p_to_up>::get_element(int p_index)
{
    return a_values[p_index];
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::remove_element(T p_element)
{
  for(int t_index = 0; t_index < a_index; t_index++)
    if(a_values[t_index] == p_element)
    {
      a_values[t_index] = a_values[a_index - 1];
      a_index--;
      return this;
    }
  return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::remove_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  iterator_micro_set<T, p_to_up> t_iterator(p_inner_set);

  while(t_iterator++ != t_iterator.end())
    remove_element(*t_iterator);

  return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::retain_all_element(inner_set<T, p_to_up>* p_inner_set)
{
  inner_set<T, p_to_up>* r_inner_set = inner_set_0<T, p_to_up>::EMPTY;

  if(p_inner_set->contains_element(a_values[0]))
    r_inner_set->add_element(a_values[0]);

  if(p_inner_set->contains_element(a_values[1]))
    r_inner_set->add_element(a_values[1]);

  if(p_inner_set->contains_element(a_values[2]))
    r_inner_set->add_element(a_values[2]);

  if(p_inner_set->contains_element(a_values[3]))
    r_inner_set->add_element(a_values[3]);

  if(p_inner_set->contains_element(a_values[4]))
    r_inner_set->add_element(a_values[4]);

  if(p_inner_set->contains_element(a_values[5]))
    r_inner_set->add_element(a_values[5]);

  if(p_inner_set->contains_element(a_values[6]))
    r_inner_set->add_element(a_values[6]);

  if(p_inner_set->contains_element(a_values[7]))
    r_inner_set->add_element(a_values[7]);

  if(p_inner_set->contains_element(a_values[8]))
    r_inner_set->add_element(a_values[8]);

  if(p_inner_set->contains_element(a_values[9]))
    r_inner_set->add_element(a_values[9]);

  if(p_inner_set->contains_element(a_values[10]))
    r_inner_set->add_element(a_values[10]);

  if(p_inner_set->contains_element(a_values[11]))
    r_inner_set->add_element(a_values[11]);

  if(p_inner_set->contains_element(a_values[12]))
    r_inner_set->add_element(a_values[12]);

  if(p_inner_set->contains_element(a_values[13]))
    r_inner_set->add_element(a_values[13]);

  if(p_inner_set->contains_element(a_values[14]))
    r_inner_set->add_element(a_values[14]);

  if(p_inner_set->contains_element(a_values[15]))
    r_inner_set->add_element(a_values[15]);

  if(p_inner_set->contains_element(a_values[16]))
    r_inner_set->add_element(a_values[16]);

  if(p_inner_set->contains_element(a_values[17]))
    r_inner_set->add_element(a_values[17]);

  if(p_inner_set->contains_element(a_values[18]))
    r_inner_set->add_element(a_values[18]);

  if(p_inner_set->contains_element(a_values[19]))
    r_inner_set->add_element(a_values[19]);

    if(r_inner_set->get_size() == 0)
    {
      delete r_inner_set;
      return this;
    }
    else
    {
      delete this;
      return r_inner_set;
    }
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::add_and_propagate(T p_element, micro_set<T, p_to_up>* p_micro_set)
{
  if(!contains_element(p_element))
  {
    p_micro_set->insert(p_element);

    return add_element(p_element);
  }

    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::add_all_and_propagate(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{

  return p_inner_set->add_all_and_propagate_reverse(this, p_micro_set);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_array_set<T, p_to_up>::add_all_and_propagate_reverse(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  for(int t_index = 0; t_index < 20; t_index++)
    p_inner_set = p_inner_set->add_and_propagate(a_values[t_index], p_micro_set);

  return p_inner_set;
}

template<typename T, int p_to_up>
int inner_array_set<T, p_to_up>::get_size()
{
    return a_index;
}
