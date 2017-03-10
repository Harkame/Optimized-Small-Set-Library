#include "inner_set.hpp"
#include "inner_set_0.hpp"
#include "inner_set_1.h"
#include "inner_set_2.h"
#include "inner_set_3.h"


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
inner_set<T>* inner_set_0<T>::add_elements(T p_elements)
{
    return nullptr;
}

template<typename T>
bool inner_set_0<T>::contains_element(T p_element)
{
    return false;
}

template<typename T>
bool inner_set_0<T>::contains_all_elements(T p_elements)
{
    return false;
}

template<typename T>
T inner_set_0<T>::get_element(int p_index)
{
    return (T) NULL;
}

template<typename T>
inner_set<T>* inner_set_0<T>::remove_element(T p_element)
{
    return this;
}

template<typename T>
inner_set<T>* inner_set_0<T>::retain_all_element(T* p_elements)
{
    return nullptr;
}

template<typename T>
int inner_set_0<T>::get_size()
{
    return 0;
}


template<typename T>
inner_set_1<T>::inner_set_1()
{

}

template<typename T>
inner_set_1<T>::inner_set_1(T p_element_1)
{
            a_values.element_1 = p_element_1;
    }

template<typename T>
inner_set_1<T>::~inner_set_1()
{

}

template<typename T>
inner_set<T>* inner_set_1<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_2<T>(*this, p_element);
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
    return false; //TODO
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
            return new inner_set_0<T>();
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_1<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_1<T>::get_size()
{
    return 1;
}


template<typename T>
inner_set_2<T>::inner_set_2()
{

}

template<typename T>
inner_set_2<T>::inner_set_2(T p_element_1, T p_element_2)
{
    a_values.element_1 = p_element_1;
    a_values.element_2 = p_element_2;
}

template<typename T>
inner_set_2<T>::inner_set_2(inner_set_1<T> inner_set_1, T p_element)
{
    a_values.element_1 = inner_set_1.a_values.element_1;                    a_values.element_2 = p_element;
}

template<typename T>
inner_set_2<T>::~inner_set_2()
{

}

template<typename T>
inner_set<T>* inner_set_2<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_3<T>(*this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_2<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_2<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element;
}

template<typename T>
bool inner_set_2<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_2<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_2<T>::remove_element(T p_element)
{
    if(a_values.element_1 == p_element)
        return new inner_set_1<T>(p_element);
    else             if(a_values.element_2 == p_element)
        return new inner_set_1<T>(a_values.element_1);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_2<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_2<T>::get_size()
{
    return 2;
}


template<typename T>
inner_set_3<T>::inner_set_3()
{

}

template<typename T>
inner_set_3<T>::inner_set_3(T p_element_1, T p_element_2, T p_element_3)
{
    a_values.element_1 = p_element_1;
    a_values.element_2 = p_element_2;
    a_values.element_3 = p_element_3;
}

template<typename T>
inner_set_3<T>::inner_set_3(inner_set_2<T> inner_set_2, T p_element)
{
    a_values.element_1 = inner_set_2.a_values.element_1;            a_values.element_2 = inner_set_2.a_values.element_2;                    a_values.element_3 = p_element;
}

template<typename T>
inner_set_3<T>::~inner_set_3()
{

}

template<typename T>
inner_set<T>* inner_set_3<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        //return new inner_set_4<T>(this, p_element);
        return nullptr;
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
    return false; //TODO
}

template<typename T>
T inner_set_3<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_3<T>::remove_element(T p_element)
{
    if(a_values.element_1 == p_element)
        return new inner_set_2<T>(a_values.element_2, a_values.element_3);
    else             if(a_values.element_2 == p_element)
        return new inner_set_2<T>(a_values.element_1, a_values.element_3);
    else             if(a_values.element_3 == p_element)
        return new inner_set_2<T>(a_values.element_1, a_values.element_2);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_3<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_3<T>::get_size()
{
    return 3;
}

template<typename T>
void inner_set_0<T>::print()
{
  cout << "{}" << endl;
}

template<typename T>
void inner_set_1<T>::print()
{
      cout << "{" << a_values.element_1 << "}" << endl;
}

template<typename T>
void inner_set_2<T>::print()
{
  cout << "{" << a_values.element_1 << a_values.element_2 << "}" << endl;
}

template<typename T>
void inner_set_3<T>::print()
{
  cout << "{" << a_values.element_1 << a_values.element_2 << a_values.element_3 << "}" << endl;

}

int main()
{
  inner_set_0<int>* i0 = new inner_set_0<int>();
  i0->print();

  inner_set<int>* i1 = i0->add_element(9);
  i1->print();

  inner_set<int>* i2 = i1->add_element(6);
  i2->print();

  inner_set<int>* i3 = i2->add_element(3);
  i3->print();

  return 0;
}
