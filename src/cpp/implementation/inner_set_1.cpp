#include "inner_set_0.hpp"
#include "inner_set_1.hpp"

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
inner_set<T>*  inner_set_1<T>::copy()
{
	return this;
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
    return inner_set_0<T>::EMPTY;
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
  inner_set<T>* r_inner_set = inner_set_0<T>::EMPTY;

  if(p_inner_set->contains_element(a_values.element_1))
    r_inner_set = r_inner_set->add_element(a_values.element_1);

  return r_inner_set;
}

template<typename T>
inner_set<T>* inner_set_1<T>::add_and_propagate(T p_element, micro_set<T>* p_micro_set)
{
  if(a_values.element_1 == p_element)
    return this;
  else
  {
	   p_micro_set->insert(p_element);

	    return new inner_set_2<T>(this, p_element);
  }
}

template<typename T>
inner_set<T>* inner_set_1<T>::add_all_and_propagate(inner_set<T>* p_inner_set, micro_set<T>* p_micro_set)
{
  return p_inner_set->add_all_and_propagate_reverse(this, p_micro_set);
}

template<typename T>
inner_set<T>* inner_set_1<T>::add_all_and_propagate_reverse(inner_set<T>* p_inner_set, micro_set<T>* p_micro_set)
{
  return p_inner_set->add_and_propagate(a_values.element_1, p_micro_set);
}

template<typename T>
int inner_set_1<T>::get_size()
{
    return 1;
}
