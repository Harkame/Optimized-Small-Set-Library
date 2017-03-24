#include "inner_set.hpp"
#include "inner_set_0.hpp"
#include "inner_set_1.hpp"
#include "inner_set_2.hpp"
#include "inner_set_3.hpp"
#include "inner_set_4.hpp"
#include "inner_set_5.hpp"
#include "inner_set_6.hpp"
#include "inner_set_7.hpp"
#include "inner_set_8.hpp"
#include "inner_set_9.hpp"
#include "inner_set_10.hpp"

#include "inner_hashset.hpp"
#include "inner_vector_set.hpp"

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
inner_set_4<T>::inner_set_4()
{

}

template<typename T>
inner_set_4<T>::inner_set_4(T p_element_1, T p_element_2, T p_element_3, T p_element_4)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
    }

template<typename T>
inner_set_4<T>::inner_set_4(inner_set_3<T> p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set.a_values.element_1;            a_values.element_2 = p_inner_set.a_values.element_2;            a_values.element_3 = p_inner_set.a_values.element_3;                    a_values.element_4 = p_element;
}

template<typename T>
inner_set_4<T>::~inner_set_4()
{

}

                                                template<typename T>
inner_set<T>* inner_set_4<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_5<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_4<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_4<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element;
}

template<typename T>
bool inner_set_4<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_4<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_4<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_3<T>( a_values.element_2,  a_values.element_3,  a_values.element_4);
         else             if(a_values.element_2 == p_element)
            return new inner_set_3<T>( a_values.element_1,  a_values.element_3,  a_values.element_4);
         else             if(a_values.element_3 == p_element)
            return new inner_set_3<T>( a_values.element_1,  a_values.element_2,  a_values.element_4);
         else             if(a_values.element_4 == p_element)
            return new inner_set_3<T>( a_values.element_1,  a_values.element_2,  a_values.element_3);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_4<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_4<T>::get_size()
{
    return 4;
}

template<typename T>
inner_set_5<T>::inner_set_5()
{

}

template<typename T>
inner_set_5<T>::inner_set_5(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
            a_values.element_5 = p_element_5;
    }

template<typename T>
inner_set_5<T>::inner_set_5(inner_set_4<T> p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set.a_values.element_1;            a_values.element_2 = p_inner_set.a_values.element_2;            a_values.element_3 = p_inner_set.a_values.element_3;            a_values.element_4 = p_inner_set.a_values.element_4;                    a_values.element_5 = p_element;
}

template<typename T>
inner_set_5<T>::~inner_set_5()
{

}

                                                template<typename T>
inner_set<T>* inner_set_5<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_6<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_5<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_5<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element ||  a_values.element_5 == p_element;
}

template<typename T>
bool inner_set_5<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_5<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_5<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_4<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5);
         else             if(a_values.element_2 == p_element)
            return new inner_set_4<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5);
         else             if(a_values.element_3 == p_element)
            return new inner_set_4<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5);
         else             if(a_values.element_4 == p_element)
            return new inner_set_4<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5);
         else             if(a_values.element_5 == p_element)
            return new inner_set_4<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_5<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_5<T>::get_size()
{
    return 5;
}

template<typename T>
inner_set_6<T>::inner_set_6()
{

}

template<typename T>
inner_set_6<T>::inner_set_6(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
            a_values.element_5 = p_element_5;
            a_values.element_6 = p_element_6;
    }

template<typename T>
inner_set_6<T>::inner_set_6(inner_set_5<T> p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set.a_values.element_1;            a_values.element_2 = p_inner_set.a_values.element_2;            a_values.element_3 = p_inner_set.a_values.element_3;            a_values.element_4 = p_inner_set.a_values.element_4;            a_values.element_5 = p_inner_set.a_values.element_5;                    a_values.element_6 = p_element;
}

template<typename T>
inner_set_6<T>::~inner_set_6()
{

}

                                                template<typename T>
inner_set<T>* inner_set_6<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_7<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_6<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_6<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element ||  a_values.element_5 == p_element ||  a_values.element_6 == p_element;
}

template<typename T>
bool inner_set_6<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_6<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_6<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_5<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6);
         else             if(a_values.element_2 == p_element)
            return new inner_set_5<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6);
         else             if(a_values.element_3 == p_element)
            return new inner_set_5<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5,  a_values.element_6);
         else             if(a_values.element_4 == p_element)
            return new inner_set_5<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5,  a_values.element_6);
         else             if(a_values.element_5 == p_element)
            return new inner_set_5<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_6);
         else             if(a_values.element_6 == p_element)
            return new inner_set_5<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_6<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_6<T>::get_size()
{
    return 6;
}

template<typename T>
inner_set_7<T>::inner_set_7()
{

}

template<typename T>
inner_set_7<T>::inner_set_7(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
            a_values.element_5 = p_element_5;
            a_values.element_6 = p_element_6;
            a_values.element_7 = p_element_7;
    }

template<typename T>
inner_set_7<T>::inner_set_7(inner_set_6<T> p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set.a_values.element_1;            a_values.element_2 = p_inner_set.a_values.element_2;            a_values.element_3 = p_inner_set.a_values.element_3;            a_values.element_4 = p_inner_set.a_values.element_4;            a_values.element_5 = p_inner_set.a_values.element_5;            a_values.element_6 = p_inner_set.a_values.element_6;                    a_values.element_7 = p_element;
}

template<typename T>
inner_set_7<T>::~inner_set_7()
{

}

                                                template<typename T>
inner_set<T>* inner_set_7<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_8<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_7<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_7<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element ||  a_values.element_5 == p_element ||  a_values.element_6 == p_element ||  a_values.element_7 == p_element;
}

template<typename T>
bool inner_set_7<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_7<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_7<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_6<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7);
         else             if(a_values.element_2 == p_element)
            return new inner_set_6<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7);
         else             if(a_values.element_3 == p_element)
            return new inner_set_6<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7);
         else             if(a_values.element_4 == p_element)
            return new inner_set_6<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5,  a_values.element_6,  a_values.element_7);
         else             if(a_values.element_5 == p_element)
            return new inner_set_6<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_6,  a_values.element_7);
         else             if(a_values.element_6 == p_element)
            return new inner_set_6<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_7);
         else             if(a_values.element_7 == p_element)
            return new inner_set_6<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_7<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_7<T>::get_size()
{
    return 7;
}

template<typename T>
inner_set_8<T>::inner_set_8()
{

}

template<typename T>
inner_set_8<T>::inner_set_8(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
            a_values.element_5 = p_element_5;
            a_values.element_6 = p_element_6;
            a_values.element_7 = p_element_7;
            a_values.element_8 = p_element_8;
    }

template<typename T>
inner_set_8<T>::inner_set_8(inner_set_7<T> p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set.a_values.element_1;            a_values.element_2 = p_inner_set.a_values.element_2;            a_values.element_3 = p_inner_set.a_values.element_3;            a_values.element_4 = p_inner_set.a_values.element_4;            a_values.element_5 = p_inner_set.a_values.element_5;            a_values.element_6 = p_inner_set.a_values.element_6;            a_values.element_7 = p_inner_set.a_values.element_7;                    a_values.element_8 = p_element;
}

template<typename T>
inner_set_8<T>::~inner_set_8()
{

}

                                                template<typename T>
inner_set<T>* inner_set_8<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_9<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_8<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_8<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element ||  a_values.element_5 == p_element ||  a_values.element_6 == p_element ||  a_values.element_7 == p_element ||  a_values.element_8 == p_element;
}

template<typename T>
bool inner_set_8<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_8<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_8<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_7<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8);
         else             if(a_values.element_2 == p_element)
            return new inner_set_7<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8);
         else             if(a_values.element_3 == p_element)
            return new inner_set_7<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8);
         else             if(a_values.element_4 == p_element)
            return new inner_set_7<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8);
         else             if(a_values.element_5 == p_element)
            return new inner_set_7<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_6,  a_values.element_7,  a_values.element_8);
         else             if(a_values.element_6 == p_element)
            return new inner_set_7<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_7,  a_values.element_8);
         else             if(a_values.element_7 == p_element)
            return new inner_set_7<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_8);
         else             if(a_values.element_8 == p_element)
            return new inner_set_7<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_8<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_8<T>::get_size()
{
    return 8;
}

template<typename T>
inner_set_9<T>::inner_set_9()
{

}

template<typename T>
inner_set_9<T>::inner_set_9(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
            a_values.element_5 = p_element_5;
            a_values.element_6 = p_element_6;
            a_values.element_7 = p_element_7;
            a_values.element_8 = p_element_8;
            a_values.element_9 = p_element_9;
    }

template<typename T>
inner_set_9<T>::inner_set_9(inner_set_8<T> p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set.a_values.element_1;            a_values.element_2 = p_inner_set.a_values.element_2;            a_values.element_3 = p_inner_set.a_values.element_3;            a_values.element_4 = p_inner_set.a_values.element_4;            a_values.element_5 = p_inner_set.a_values.element_5;            a_values.element_6 = p_inner_set.a_values.element_6;            a_values.element_7 = p_inner_set.a_values.element_7;            a_values.element_8 = p_inner_set.a_values.element_8;                    a_values.element_9 = p_element;
}

template<typename T>
inner_set_9<T>::~inner_set_9()
{

}

                                                template<typename T>
inner_set<T>* inner_set_9<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_set_10<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_9<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_9<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element ||  a_values.element_5 == p_element ||  a_values.element_6 == p_element ||  a_values.element_7 == p_element ||  a_values.element_8 == p_element ||  a_values.element_9 == p_element;
}

template<typename T>
bool inner_set_9<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_9<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_9<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_8<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
         else             if(a_values.element_2 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
         else             if(a_values.element_3 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
         else             if(a_values.element_4 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
         else             if(a_values.element_5 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
         else             if(a_values.element_6 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_7,  a_values.element_8,  a_values.element_9);
         else             if(a_values.element_7 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_8,  a_values.element_9);
         else             if(a_values.element_8 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_9);
         else             if(a_values.element_9 == p_element)
            return new inner_set_8<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_9<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_9<T>::get_size()
{
    return 9;
}

template<typename T>
inner_set_10<T>::inner_set_10()
{

}

template<typename T>
inner_set_10<T>::inner_set_10(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10)
{
            a_values.element_1 = p_element_1;
            a_values.element_2 = p_element_2;
            a_values.element_3 = p_element_3;
            a_values.element_4 = p_element_4;
            a_values.element_5 = p_element_5;
            a_values.element_6 = p_element_6;
            a_values.element_7 = p_element_7;
            a_values.element_8 = p_element_8;
            a_values.element_9 = p_element_9;
            a_values.element_10 = p_element_10;
    }

template<typename T>
inner_set_10<T>::inner_set_10(inner_set_9<T> p_inner_set, T p_element)
{
            a_values.element_1 = p_inner_set.a_values.element_1;            a_values.element_2 = p_inner_set.a_values.element_2;            a_values.element_3 = p_inner_set.a_values.element_3;            a_values.element_4 = p_inner_set.a_values.element_4;            a_values.element_5 = p_inner_set.a_values.element_5;            a_values.element_6 = p_inner_set.a_values.element_6;            a_values.element_7 = p_inner_set.a_values.element_7;            a_values.element_8 = p_inner_set.a_values.element_8;            a_values.element_9 = p_inner_set.a_values.element_9;                    a_values.element_10 = p_element;
}

template<typename T>
inner_set_10<T>::~inner_set_10()
{

}

                                                template<typename T>
inner_set<T>* inner_set_10<T>::add_element(T p_element)
{
    if(!contains_element(p_element))
        return new inner_hashset<T>(this, p_element);
    else
        return this;
}

template<typename T>
inner_set<T>* inner_set_10<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_set_10<T>::contains_element(T p_element)
{
    return  a_values.element_1 == p_element ||  a_values.element_2 == p_element ||  a_values.element_3 == p_element ||  a_values.element_4 == p_element ||  a_values.element_5 == p_element ||  a_values.element_6 == p_element ||  a_values.element_7 == p_element ||  a_values.element_8 == p_element ||  a_values.element_9 == p_element ||  a_values.element_10 == p_element;
}

template<typename T>
bool inner_set_10<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_set_10<T>::get_element(int p_index)
{
    return reinterpret_cast<T*>(&a_values)[p_index];
}

template<typename T>
inner_set<T>* inner_set_10<T>::remove_element(T p_element)
{
            if(a_values.element_1 == p_element)
            return new inner_set_9<T>( a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_2 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_3 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_4 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_5 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_6 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_7,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_7 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_8,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_8 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_9,  a_values.element_10);
         else             if(a_values.element_9 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_10);
         else             if(a_values.element_10 == p_element)
            return new inner_set_9<T>( a_values.element_1,  a_values.element_2,  a_values.element_3,  a_values.element_4,  a_values.element_5,  a_values.element_6,  a_values.element_7,  a_values.element_8,  a_values.element_9);
                else
        return this;
}

template<typename T>
inner_set<T>* inner_set_10<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_set_10<T>::get_size()
{
    return 10;
}

/*********************/

template<typename T>
inner_hashset<T>::inner_hashset()
{

}

template<typename T>
inner_hashset<T>::inner_hashset(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10)
{
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
            //TODO
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

/*******/

template<typename T>
inner_vector_set<T>::inner_vector_set()
{

}

template<typename T>
inner_vector_set<T>::inner_vector_set(T p_element_1, T p_element_2, T p_element_3, T p_element_4, T p_element_5, T p_element_6, T p_element_7, T p_element_8, T p_element_9, T p_element_10)
{
            a_values->push_back(p_element_1);
            a_values->push_back(p_element_2);
            a_values->push_back(p_element_3);
            a_values->push_back(p_element_4);
            a_values->push_back(p_element_5);
            a_values->push_back(p_element_6);
            a_values->push_back(p_element_7);
            a_values->push_back(p_element_8);
            a_values->push_back(p_element_9);
            a_values->push_back(p_element_10);
    }

template<typename T>
inner_vector_set<T>::inner_vector_set(inner_set_10<T> p_inner_set, T p_element)
{
            //TODO
}

template<typename T>
inner_vector_set<T>::~inner_vector_set()
{

}

                                                template<typename T>
inner_set<T>* inner_vector_set<T>::add_element(T p_element)
{
    if(!contains_element)
      a_values->push_back(p_element);

    return this;
}

template<typename T>
inner_set<T>* inner_vector_set<T>::add_elements(T* p_elements)
{
    return nullptr; //TODO
}

template<typename T>
bool inner_vector_set<T>::contains_element(T p_element)
{
  return find(a_values.begin(), a_values.end(), p_element) != a_values.end();
}

template<typename T>
bool inner_vector_set<T>::contains_all_elements(T* p_elements)
{
    return false; //TODO
}

template<typename T>
T inner_vector_set<T>::get_element(int p_index)
{
    return a_values->at(p_index);
}

template<typename T>
inner_set<T>* inner_vector_set<T>::remove_element(T p_element)
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
inner_set<T>* inner_vector_set<T>::retain_all_element(T* p_elements)
{
    return this; //TODO
}

template<typename T>
int inner_vector_set<T>::get_size()
{
    return a_values->size();
}
