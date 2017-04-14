#include "inner_hash_set.hpp"
#include "inner_array_set.hpp"

template<typename T>
inner_hash_set<T>::inner_hash_set()
{
  a_values = new set<T>();
}

template<typename T>
inner_hash_set<T>::inner_hash_set(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10)
{
  a_values = new set<T>();

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
inner_hash_set<T>::inner_hash_set(inner_array_set<T>* p_inner_set, T p_element)
{
  a_values = new set<T>();

  a_values->insert(p_inner_set.a_values[0]);
  a_values->insert(p_inner_set.a_values[1]);
  a_values->insert(p_inner_set.a_values[2]);
  a_values->insert(p_inner_set.a_values[3]);
  a_values->insert(p_inner_set.a_values[4]);
  a_values->insert(p_inner_set.a_values[5]);
  a_values->insert(p_inner_set.a_values[6]);
  a_values->insert(p_inner_set.a_values[7]);
  a_values->insert(p_inner_set.a_values[8]);
  a_values->insert(p_inner_set.a_values[9]);
  a_values->insert(p_inner_set.a_values[10]);
  a_values->insert(p_inner_set.a_values[11]);
  a_values->insert(p_inner_set.a_values[12]);
  a_values->insert(p_inner_set.a_values[13]);
  a_values->insert(p_inner_set.a_values[14]);
  a_values->insert(p_inner_set.a_values[15]);
  a_values->insert(p_inner_set.a_values[16]);
  a_values->insert(p_inner_set.a_values[17]);
  a_values->insert(p_inner_set.a_values[18]);
  a_values->insert(p_inner_set.a_values[19]);

  a_values->insert(p_element);
}

template<typename T>
inner_hash_set<T>::inner_hash_set(inner_set_10<T> p_inner_set)
{
  a_values = new set<T>();
}

template<typename T>
inner_hash_set<T>::~inner_hash_set()
{

}

                                                template<typename T>
inner_set<T>* inner_hash_set<T>::add_element(T p_element)
{
    a_values->insert(p_element);

    return this;
}

template<typename T>
inner_set<T>* inner_hash_set<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_hash_set<T>::contains_element(T p_element)
{
  return (find(p_element) == p_element);
}

template<typename T>
bool inner_hash_set<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_hash_set<T>::get_element(int p_index)
{
    return a_values->at(p_index);
}

template<typename T>
inner_set<T>* inner_hash_set<T>::remove_element(T p_element)
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
inner_set<T>* inner_hash_set<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_hash_set<T>::get_size()
{
    return a_values->size();
}
