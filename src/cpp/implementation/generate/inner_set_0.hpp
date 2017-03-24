#ifndef INNER_SET_0_H
#define INNER_SET_0_H

#include <cstddef>
#include <iostream>

#include "inner_set.hpp"
#include "inner_set_1.hpp"

using namespace std;

template<typename T>
class inner_set_0 : public inner_set<T>
{
    private :
        struct values
        {

        } a_values;

    public :
        static inner_set_0<T>* INNER_SET_0();

        inner_set_0<T>();

        virtual ~inner_set_0<T>();

        virtual inner_set<T>* add_element(T);

        virtual inner_set<T>* add_elements(T);

        virtual bool contains_element(T);

        virtual bool contains_all_elements(T);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);

        virtual inner_set<T>* retain_all_element(T*);

        virtual int get_size();
};

#endif
