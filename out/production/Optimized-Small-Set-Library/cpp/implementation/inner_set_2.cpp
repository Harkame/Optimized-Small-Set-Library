#include "inner_set.hpp"
#include "inner_set_1.hpp"
#include "inner_set_2.hpp"
#include <stdlib.h>

using namespace std;

template<typename T>
inner_set_2<T>::inner_set_2()
{
	a_values = new T*[2];
}

template<typename T>
inner_set_2<T>::inner_set_2(T* p_element_1, T* p_element_2)
{
	a_values = new T*[2];

	a_values[0] = p_element_1;
	a_values[1] = p_element_2;
}

/*
template<typename T>
inner_set_2<T>::inner_set_2(inner_set_1<T>* p_inner_set, T* p_element) : inner_set<T>()
{
	a_values = new T*[2];

	a_values[0] = p_inner_set->a_values[0];
	a_values[1] = p_element;
}
*/


template<typename T>
inner_set_2<T>::~inner_set_2()
{

}

template<typename T>
inner_set<T>* inner_set_2<T>::add_element(T* p_element)
{
    return nullptr; //TODO, inner_set_3
}

template<typename T>
inner_set<T>* inner_set_2<T>::add_elements(T** p_elements)
{
	return nullptr; //TODO
}

template<typename T>
bool inner_set_2<T>::contains_element(T* p_element)
{
    return a_values[0] == p_element ||
    		a_values[1] == p_element;
}

template<typename T>
bool inner_set_2<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T* inner_set_2<T>::get_element(int p_index)
{
    return a_values[p_index];
}

template<typename T>
inner_set<T>* inner_set_2<T>::remove_element(T* p_element)
{
    if(a_values[0] == p_element)
    {
    	return new inner_set_1<T>(a_values[0]);
    }
    else if(a_values[1] == p_element)
    	return new inner_set_1<T>(a_values[1]);
    else
    	return this;
}

template<typename T>
inner_set<T>* inner_set_2<T>::retain_all_element(T** p_elements)
{
    return this;
}

template<typename T>
int inner_set_2<T>::get_size()
{
    return 2;
}
