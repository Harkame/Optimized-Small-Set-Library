#include "inner_set_1.hpp"

template<typename T>
inner_set_1<T>::inner_set_1()
{

}

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
    return new inner_set_2<T>(a_values.element_1, p_element);
}

template<typename T>
inner_set<T>* inner_set_1<T>::add_elements(T* p_elements)
{
	return nullptr;
}

template<typename T>
bool inner_set_1<T>::contains_element(T p_element)
{
    return false;
}

template<typename T>
bool inner_set_1<T>::contains_all_elements(T* p_elements)
{
    return false;
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
		return &INNER_SET_0;
	else
		return this;
}

template<typename T>
inner_set<T>* inner_set_1<T>::retain_all_element(T* p_elements)
{
	//TODO
	return nullptr;
}

template<typename T>
int inner_set_1<T>::get_size()
{
    return 0;
}

template<typename T>
void inner_set_1<T>::print()
{
    cout << "{" << a_values.element_1 << "}" << endl;
}
