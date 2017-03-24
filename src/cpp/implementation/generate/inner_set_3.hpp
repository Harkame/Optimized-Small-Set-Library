#ifndef INNER_SET_3_H
#define INNER_SET_3_H


#include "inner_set.hpp"
#include "inner_set_2.hpp"

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
        inner_set_3<T>(T , T , T );
        inner_set_3<T>(inner_set_2<T>, T);

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
