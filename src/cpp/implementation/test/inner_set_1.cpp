#include "$innerSetClassName.hpp"

#include <iostream>

template<typename T>
inner_set_1<T>::inner_set_1()
{

}

template<typename T>
public inner_set_1(T p_element_1)
{
            a_values.element_1 = p_element_1;
    }

template<typename T>
inner_set_1<T>::inner_set_1(T inner_set_0, T p_element)
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
    if(!contains_element(p_element);
        return new inner_set_2<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_1<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_1<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element;
}

template<typename T>
bool inner_set_1<T>::contains_all_elements(T* p_elements)
{
    return false //TODO
}

template<typename T>
T inner_set_1<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_1<T>::remove_element(T p_element)
{
            if(element_1 == p_element)
            return new inner_set_0<>();
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_1<T>::retain_all_element(T** p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_1<T>::get_size()
{
    return 1;
}
