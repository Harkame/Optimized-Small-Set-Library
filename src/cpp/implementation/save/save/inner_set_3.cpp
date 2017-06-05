#include "inner_set_0.hpp"
#include "inner_set_3.hpp"

#include "inner_array_set.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

template<typename T, int p_to_up>
inner_set_3<T, p_to_up>::inner_set_3()
{

}

template<typename T, int p_to_up>
inner_set_3<T, p_to_up>::inner_set_3(T p_element_1, T p_element_2, T p_element_3)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
    }

template<typename T, int p_to_up>
inner_set_3<T, p_to_up>::inner_set_3(inner_set_2<T, p_to_up>* p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set->a_values.element_1;
            a_values.element_2 = p_inner_set->a_values.element_2;

            a_values.element_3 = p_element;

            delete p_inner_set;
}

template<typename T, int p_to_up>
inner_set_3<T, p_to_up>::~inner_set_3()
{

}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::add_element(T p_element)
{
  if(!contains_element(p_element))
    if(this->a_to_up == 3)
      return new inner_array_set<T, p_to_up>(this, p_element);
    else
      return new inner_array_set<T, p_to_up>(this, p_element); //TODO 4
  else
    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::add_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->add_element(a_values.element_1)->add_element(a_values.element_2)->add_element(a_values.element_3);
}

template<typename T, int p_to_up>
bool inner_set_3<T, p_to_up>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element;
}

template<typename T, int p_to_up>
bool inner_set_3<T, p_to_up>::contains_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->contains_element(a_values.element_1) &&
    p_inner_set->contains_element(a_values.element_2);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>*  inner_set_3<T, p_to_up>::copy()
{
	return this;
}

template<typename T, int p_to_up>
T inner_set_3<T, p_to_up>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::remove_element(T p_element)
{
  T t_value_1 = {};
  T t_value_2 = {};

  if(a_values.element_1 == p_element)
  {
    t_value_1 = a_values.element_2;
    t_value_2 = a_values.element_3;

    delete this;

    return new inner_set_2<T, p_to_up>(t_value_1, t_value_2);
  }
  else if(a_values.element_2 == p_element)
  {
    t_value_1 = a_values.element_1;
    t_value_2 = a_values.element_3;

    delete this;

    return new inner_set_2<T, p_to_up>(t_value_1, t_value_2);
  }
  else if(a_values.element_3 == p_element)
  {
    t_value_1 = a_values.element_1;
    t_value_2 = a_values.element_2;

    delete this;

    return new inner_set_2<T, p_to_up>(t_value_1, t_value_2);
  }
  else
    return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::remove_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  return p_inner_set->remove_element(a_values.element_1)->remove_element(a_values.element_2)->remove_element(a_values.element_3);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::retain_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
  inner_set<T, p_to_up>* r_inner_set = inner_set_0<T, p_to_up>::EMPTY;

  if(p_inner_set->contains_element(a_values.element_1))
    r_inner_set = r_inner_set->add_element(a_values.element_1);

  if(p_inner_set->contains_element(a_values.element_2))
    r_inner_set = r_inner_set->add_element(a_values.element_2);

  if(p_inner_set->contains_element(a_values.element_3))
    r_inner_set = r_inner_set->add_element(a_values.element_3);

    if(this->get_size() != 0)
      delete this;

  return r_inner_set;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::add_and_propagate(T p_element, micro_set<T, p_to_up>* p_micro_set)
{
  if(a_values.element_1 == p_element ||
    a_values.element_2 == p_element ||
    a_values.element_3 == p_element)
    return this;
  else
  {
	   p_micro_set->insert(p_element);

	    return new inner_array_set<T, p_to_up>(this, p_element);
  }
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::add_all_and_propagate(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  return p_inner_set->add_all_and_propagate_reverse(this, p_micro_set);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_3<T, p_to_up>::add_all_and_propagate_reverse(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
  return p_inner_set->add_and_propagate(a_values.element_1, p_micro_set)->add_and_propagate(a_values.element_2, p_micro_set)->add_and_propagate(a_values.element_3, p_micro_set);
}

template<typename T, int p_to_up>
int inner_set_3<T, p_to_up>::get_size()
{
    return 3;
}
