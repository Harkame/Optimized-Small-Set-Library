#include "inner_array_set.hpp"

#include "inner_tree_set.hpp"
#include <iostream>

template<typename T>
inner_array_set<T>::inner_array_set()
{
  a_index = 0;

  a_values = new T[20];
}

template<typename T>
inner_array_set<T>::inner_array_set(inner_set_5<T>* p_inner_set, T p_element)
{
  a_index = 6;

  a_values = new T[20];

  a_values[0] = p_inner_set->a_values.element_1;
  a_values[1] = p_inner_set->a_values.element_2;
  a_values[2] = p_inner_set->a_values.element_3;
  a_values[3] = p_inner_set->a_values.element_4;
  a_values[4] = p_inner_set->a_values.element_5;

  a_values[5] = p_element;

  delete p_inner_set;
}

template<typename T>
inner_array_set<T>::~inner_array_set()
{

}

template<typename T>
inner_set<T>* inner_array_set<T>::add_element(T p_element)
{
  if(a_index == 19)
  {
    if(!contains_element(p_element))
      return new inner_tree_set<T>(this, p_element);
  }
  else
    if(!contains_element(p_element))
      a_values[a_index++] = p_element;

  return this;
}

template<typename T>
inner_set<T>* inner_array_set<T>::add_all_elements(inner_set<T>* p_inner_set)
{
    return p_inner_set->add_element(a_values[0])->add_element(a_values[1])->add_element(a_values[2])->add_element(a_values[3])->add_element(a_values[4])->add_element(a_values[5])->add_element(a_values[6])->add_element(a_values[7])->add_element(a_values[8])->add_element(a_values[9])->add_element(a_values[10])->add_element(a_values[11])->add_element(a_values[12])->add_element(a_values[13])->add_element(a_values[14])->add_element(a_values[15])->add_element(a_values[16])->add_element(a_values[17])->add_element(a_values[18])->add_element(a_values[19]);
}

template<typename T>
bool inner_array_set<T>::contains_element(T p_element)
{
  return a_values[0] == p_element ||
    a_values[1] == p_element   ||
    a_values[2] == p_element   ||
    a_values[3] == p_element   ||
    a_values[4] == p_element   ||
    a_values[5] == p_element   ||
    a_values[6] == p_element   ||
    a_values[7] == p_element   ||
    a_values[8] == p_element   ||
    a_values[9] == p_element   ||
    a_values[10] == p_element ||
    a_values[11] == p_element ||
    a_values[12] == p_element ||
    a_values[13] == p_element ||
    a_values[14] == p_element ||
    a_values[15] == p_element ||
    a_values[16] == p_element ||
    a_values[17] == p_element ||
    a_values[18] == p_element ||
    a_values[19] == p_element;
}

template<typename T>
bool inner_array_set<T>::contains_all_elements(inner_set<T>* p_inner_set)
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

template<typename T>
T inner_array_set<T>::get_element(int p_index)
{
    return a_values[p_index];
}

template<typename T>
inner_set<T>* inner_array_set<T>::remove_element(T p_element)
{
  if(a_index == 5)
  {
    T t_value_1;
    T t_value_2;
    T t_value_3;
    T t_value_4;
    T t_value_5;

    if(a_values[0] == p_element)
    {
      t_value_1 = a_values[1];
      t_value_2 = a_values[2];
      t_value_3 = a_values[3];
      t_value_4 = a_values[4];
      t_value_5 = a_values[5];
    }
    else if(a_values[1] == p_element)
    {
      t_value_1 = a_values[0];
      t_value_2 = a_values[2];
      t_value_3 = a_values[3];
      t_value_4 = a_values[4];
      t_value_5 = a_values[5];
    }
    else if(a_values[2] == p_element)
    {
      t_value_1 = a_values[0];
      t_value_2 = a_values[1];
      t_value_3 = a_values[3];
      t_value_4 = a_values[4];
      t_value_5 = a_values[5];
    }
    else if(a_values[3] == p_element)
    {
      t_value_1 = a_values[0];
      t_value_2 = a_values[1];
      t_value_3 = a_values[2];
      t_value_4 = a_values[4];
      t_value_5 = a_values[5];
    }
    else if(a_values[4] == p_element)
    {
      t_value_1 = a_values[0];
      t_value_2 = a_values[1];
      t_value_3 = a_values[2];
      t_value_4 = a_values[3];
      t_value_5 = a_values[5];
    }
    else if(a_values[5] == p_element)
    {
      t_value_1 = a_values[0];
      t_value_2 = a_values[1];
      t_value_3 = a_values[2];
      t_value_4 = a_values[3];
      t_value_5 = a_values[4];
    }

    delete this;

    return new inner_set_5<T>(t_value_1, t_value_2, t_value_3, t_value_4, t_value_5);
  }
  else
  {
    for(int t_index = 0; t_index < a_index; t_index++)
      if(a_values[t_index] == p_element)
      {
        a_values[t_index] = a_values[a_index--];
        return this;
      }
  }
    return this;
}

template<typename T>
inner_set<T>* inner_array_set<T>::remove_all_elements(inner_set<T>* p_inner_set)
{
    return p_inner_set->add_element(a_values[0])->add_element(a_values[1])->add_element(a_values[2])->add_element(a_values[3])->add_element(a_values[4])->add_element(a_values[5])->add_element(a_values[6])->add_element(a_values[7])->add_element(a_values[8])->add_element(a_values[9])->add_element(a_values[10])->add_element(a_values[11])->add_element(a_values[12])->add_element(a_values[13])->add_element(a_values[14])->add_element(a_values[15])->add_element(a_values[16])->add_element(a_values[17])->add_element(a_values[18])->add_element(a_values[19]);
}

template<typename T>
inner_set<T>* inner_array_set<T>::retain_all_element(inner_set<T>* p_inner_set)
{
  inner_set<T>* r_inner_set = new inner_array_set<T>;

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

  return r_inner_set;
}

template<typename T>
int inner_array_set<T>::get_size()
{
    return a_index;
}
