#include "inner_set_0.hpp"
#include "inner_set.hpp"

template<typename T>
inner_set_0<T>::inner_set_0()
{

}

template<typename T>
inner_set_0<T>::~inner_set_0()
{

}

template<typename T>
inner_set<T>* inner_set_0<T>::add_element(T p_element)
{
	return new inner_set_1<T>(p_element);
}

template<typename T>
inner_set<T>* inner_set_0<T>::add_all_elements(inner_set<T>* p_inner_set)
{
	cout << "addall" << endl;
}

template<typename T>
bool inner_set_0<T>::contains_element(T p_element)
{
	p_element = p_element;
	return false;
}

template<typename T>
bool inner_set_0<T>::contains_all_elements(inner_set<T>* p_inner_set)
{
	p_inner_set = p_inner_set;
  return false;
}

template<typename T>
T inner_set_0<T>::get_element(int p_index)
{
		p_index = p_index;
    return (T) NULL;
}

template<typename T>
inner_set<T>* inner_set_0<T>::remove_element(T p_element)
{
	p_element = p_element;
  return this;
}

template<typename T>
inner_set<T>* inner_set_0<T>::remove_all_elements(inner_set<T>* p_inner_set)
{
	p_inner_set = p_inner_set;

  return this;
}

template<typename T>
inner_set<T>* inner_set_0<T>::retain_all_elements(inner_set<T>* p_inner_set)
{
    return p_inner_set;
}

template<typename T>
inner_set<T>* inner_set_0<T>::add_and_propagate(T p_element, micro_set<T>* p_micro_set)
{
	p_micro_set->insert(p_element);

	return new inner_set_1<T>(p_element);
}

template<typename T>
inner_set<T>* inner_set_0<T>::add_all_and_propagate(inner_set<T>* p_inner_set, micro_set<T>* p_micro_set)
{
	p_micro_set->a_inner_set = p_micro_set->a_inner_set->add_all_elements(p_inner_set);

	return p_inner_set;
}

template<typename T>
inner_set<T>* inner_set_0<T>::add_all_and_propagate_reverse(inner_set<T>* p_inner_set, micro_set<T>* p_micro_set)
{
	return p_inner_set;
}

template<typename T>
int inner_set_0<T>::get_size()
{
    return 0;
}
