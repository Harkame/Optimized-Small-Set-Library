#ifndef INNER_SET_3_H
#define INNER_SET_3_H


#include "inner_set.hpp"

using namespace std;

template<typename T>
class inner_set_3 : public inner_set<T>
{
    public :
        struct values
        {
             T element_1;  T element_2;  T element_3;
        } a_values;

        inner_set_3<T>();
        public inner_set_3(T , T , T );
        inner_set_3<T>(inner_set_2, T);

        virtual ~inner_set_3<T>();

        virtual inner_set<T>* add_element(T);
        virtual inner_set<T>* add_elements(T*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(T*);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);

        virtual inner_set<T>* retain_all_element(T*);

        virtual int get_size();
};

#endif

#include "$innerSetClassName.hpp"

#include <iostream>

template<typename T>
inner_set_3<T>::inner_set_3()
{

}

template<typename T>
public inner_set_3(T p_element_1, T p_element_2, T p_element_3)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
    }

template<typename T>
inner_set_3<T>::inner_set_3(T inner_set_2, T p_element)
{
            a_values.element_1 = i.element_1;            a_values.element_2 = i.element_2;                    a_values.element_3 = p_element;
}

template<typename T>
inner_set_3<T>::~inner_set_3()
{

}

                                                template<typename T>
inner_set<T>* inner_set_3<T>::add_element(T p_element)
{
    if(!contains_element(p_element);
        return new inner_set_4<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_3<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_3<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element;
}

template<typename T>
bool inner_set_3<T>::contains_all_elements(T* p_elements)
{
    return false //TODO
}

template<typename T>
T inner_set_3<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_3<T>::remove_element(T p_element)
{
            if(element_1 == p_element)
            return new inner_set_2<>(element_2, element_3);
         else             if(element_2 == p_element)
            return new inner_set_2<>(element_1, element_3);
         else             if(element_3 == p_element)
            return new inner_set_2<>(element_1, element_2);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_3<T>::retain_all_element(T** p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_3<T>::get_size()
{
    return 3;
}
