#include "inner_set_1.hpp"
#include "inner_set_2.hpp"

template<typename T>
inner_set_1<T>::inner_set_1(T p_element)
{
  a_values.element_1 = p_element;
}

template<typename T>
inner_set_1<T>::~inner_set_1()
{

}

template<typename T>
inner_set<T>* inner_set_1<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_2<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_1<T>::add_all_elements(inner_set<T>* p_inner_set)
{
    return p_inner_set->add_element(a_values.element_1);
}

template<typename T>
bool inner_set_1<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element;
}

template<typename T>
bool inner_set_1<T>::contains_all_elements(inner_set<T>* p_inner_set)
{
  return p_inner_set->contains_element(a_values.element_1);
}

template<typename T>
T inner_set_1<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_1<T>::remove_element(T p_element)
{
  if(a_values.element_1 == p_element)
  {
    delete this;

    return new inner_set_0<T>();
  }
  else
    return this;
}

template<typename T>
inner_set<T>* inner_set_1<T>::remove_all_elements(inner_set<T>* p_inner_set)
{
  return p_inner_set->remove_element(a_values.element_1);
}

template<typename T>
inner_set<T>* inner_set_1<T>::retain_all_elements(inner_set<T>* p_inner_set)
{
  inner_set<T>* r_inner_set = new inner_set_0<T>();;

  if(p_inner_set->contains_element(a_values.element_1))
    r_inner_set = r_inner_set->add_element(a_values.element_1);

  return r_inner_set;
}

template<typename T>
int inner_set_1<T>::get_size()
{
    return 1;
}
