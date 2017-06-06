#include "inner_set_0.hpp"
#include "inner_set_2.hpp"

#include "inner_array_set.hpp"

template<typename T, int p_to_up>
inner_set_0<T, p_to_up>* inner_set_0<T, p_to_up>::EMPTY = new inner_set_0<T, p_to_up>();

template<typename T, int p_to_up>
inner_set_0<T, p_to_up>::inner_set_0()
{
}

template<typename T, int p_to_up>
inner_set_0<T, p_to_up>::~inner_set_0()
{

}

template<typename T, int p_to_up>
inner_set<T, p_to_up>*  inner_set_0<T, p_to_up>::copy()
{
	return inner_set_0<T, p_to_up>::EMPTY;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::add_element(T p_element)
{
	if(this->a_to_up == 0)
		return new inner_array_set<T, p_to_up>(p_element);
	else
		return new inner_set_1<T, p_to_up>(p_element);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::add_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
	return p_inner_set->copy();
}

template<typename T, int p_to_up>
bool inner_set_0<T, p_to_up>::contains_element(T p_element)
{
	p_element = p_element;
	return false;
}

template<typename T, int p_to_up>
bool inner_set_0<T, p_to_up>::contains_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
	p_inner_set = p_inner_set;
  return false;
}

template<typename T, int p_to_up>
T inner_set_0<T, p_to_up>::get_element(int p_index)
{
		p_index = p_index;
    return (T) NULL;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::remove_element(T p_element)
{
	p_element = p_element;

	return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::remove_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
	p_inner_set = p_inner_set;

  return this;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::retain_all_elements(inner_set<T, p_to_up>* p_inner_set)
{
    return p_inner_set;
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::add_and_propagate(T p_element, micro_set<T, p_to_up>* p_micro_set)
{
	p_micro_set->insert(p_element);

	return new inner_set_1<T, p_to_up>(p_element);
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::add_all_and_propagate(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
	p_micro_set->a_inner_set = p_micro_set->a_inner_set->add_all_elements(p_inner_set);

	return p_inner_set->copy();
}

template<typename T, int p_to_up>
inner_set<T, p_to_up>* inner_set_0<T, p_to_up>::add_all_and_propagate_reverse(inner_set<T, p_to_up>* p_inner_set, micro_set<T, p_to_up>* p_micro_set)
{
	p_micro_set = p_micro_set;
	return p_inner_set->copy();
}

template<typename T, int p_to_up>
int inner_set_0<T, p_to_up>::get_size()
{
    return 0;
}
