#include "inner_array_set.hpp"

#include "inner_set_5.hpp"

template<typename T>
inner_array_set<T>::inner_array_set()
{
  a_values = new T[20];

  a_index = 0;
}

template<typename T>
inner_array_set<T>::inner_array_set(inner_set_5<T>* p_inner_set, T p_element)
{
  a_values = new T[20];

  a_values[0] = p_inner_set->a_values.element_1;
  a_values[1] = p_inner_set->a_values.element_2;
  a_values[2] = p_inner_set->a_values.element_3;
  a_values[3] = p_inner_set->a_values.element_4;
  a_values[4] = p_inner_set->a_values.element_5;

  a_values[5] = p_element;

  a_index = 6;

  for(int index = 0; index < a_index; index++)
    cout << a_values[index] << endl;
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
        //return new inner_hashset<T>(this, p_element);
      //  return new inner_hashset<T>();
      return new inner_set_0<T>();
  }
  else
    if(!contains_element(p_element))
      a_values[a_index++] = p_element;

  return this;
}

template<typename T>
inner_set<T>* inner_array_set<T>::add_elements(T* p_elements)
{
    return new inner_array_set<T>();
}

template<typename T>
bool inner_array_set<T>::contains_element(T p_element)
{
    //return a_values.element_1 == p_element;
    return true;
}

template<typename T>
bool inner_array_set<T>::contains_all_elements(T* p_elements)
{
  return true;
}

template<typename T>
T inner_array_set<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_array_set<T>::remove_element(T p_element)
{
  if(a_index == 5)
  {
    if(a_values[0] == p_element)
      return new inner_set_5<T>(a_values[1], a_values[2], a_values[3], a_values[4], a_values[5]);
    if(a_values[1] == p_element)
      return new inner_set_5<T>(a_values[0], a_values[2], a_values[3], a_values[4], a_values[5]);
    if(a_values[2] == p_element)
      return new inner_set_5<T>(a_values[0], a_values[1], a_values[3], a_values[4], a_values[5]);
    if(a_values[3] == p_element)
      return new inner_set_5<T>(a_values[0], a_values[1], a_values[2], a_values[4], a_values[5]);
    if(a_values[4] == p_element)
      return new inner_set_5<T>(a_values[0], a_values[1], a_values[22], a_values[3], a_values[4]);
  }
  else
    for(int index = 5; index < a_index; index++)
      if(a_values[index] == p_element)
        a_values[index] = a_values[a_index--];
}

template<typename T>
inner_set<T>* inner_array_set<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_array_set<T>::get_size()
{
    return a_index;
}
