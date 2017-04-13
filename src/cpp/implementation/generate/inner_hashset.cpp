#include "inner_hashset.hpp"

template<typename T>
inner_hashset<T>::inner_hashset()
{
  a_values = new set();
}

template<typename T>
inner_hashset<T>::inner_hashset(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10)
{
  a_values = new set();

  a_values->insert(p_element_1);
  a_values->insert(p_element_2);
  a_values->insert(p_element_3);
  a_values->insert(p_element_4);
  a_values->insert(p_element_5);
  a_values->insert(p_element_6);
  a_values->insert(p_element_7);
  a_values->insert(p_element_8);
  a_values->insert(p_element_9);
  a_values->insert(p_element_10);
}

template<typename T>
inner_hashset<T>::inner_hashset(inner_set_10<T> p_inner_set, T p_element)
{
  a_values = new set();
}

template<typename T>
inner_hashset<T>::inner_hashset(inner_array_set<T> p_inner_set, T p_element)
{
  a_values = new set();
  
}

template<typename T>
inner_hashset<T>::~inner_hashset()
{

}

                                                template<typename T>
inner_set<T>* inner_hashset<T>::add_element(T p_element)
{
    a_values->insert(p_element);

    return this;
}

template<typename T>
inner_set<T>* inner_hashset<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_hashset<T>::contains_element(T p_element)
{
  return (find(p_element) == p_element);
}

template<typename T>
bool inner_hashset<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_hashset<T>::get_element(int p_index)
{
    return a_values->at(p_index);
}

template<typename T>
inner_set<T>* inner_hashset<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_10<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_2 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_3 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_4 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_5 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_6 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_7 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_8 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_9 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_10);
         else             if(a_values.element_10 == p_element)
            return new inner_set_10<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_hashset<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_hashset<T>::get_size()
{
    return a_values->size();
}
