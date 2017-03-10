#include "inner_set_2.hpp"

template<typename T>
inner_set_2<T>::inner_set_2()
{

}

template<typename T>
inner_set<T>* inner_set_2<T>::add_element(T p_element)
{
    return new inner_set_1<T>(p_element);
}

template<typename T>
inner_set<T>* inner_set_2<T>::add_elements(T p_elements)
{
	return nullptr;
}

template<typename T>
bool inner_set_2<T>::contains_element(T p_element)
{
    return false;
}

template<typename T>
bool inner_set_2<T>::contains_all_elements(T p_elements)
{
    return false;
}

template<typename T>
T inner_set_2<T>::get_element(int p_index)
{
	return (T*) &a_values[p_index];
}

template<typename T>
inner_set<T>* inner_set_2<T>::remove_element(T p_element)
{
    if(a_values.element_1 == p_element)
    	return new inner_set_1<T>(a_values.element_1);
    else if(a_values.element_2 == p_element)
    	return new inner_set_1<T>(a_values.element_2);
    else
    	return this;
}

template<typename T>
inner_set<T> inner_set_2<T>::retain_all_element(T p_elements)
{
    return *this;
}

template<typename T>
int inner_set_2<T>::get_size()
{
    return 0;
}
