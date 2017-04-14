#ifndef INNER_ARRAY_SET_HPP
#define INNER_ARRAY_SET_HPP


#include <cstddef>
#include <iostream>

#include "inner_set.hpp"
#include "inner_set_5.hpp"
#include "inner_hash_set.hpp"

using namespace std;

template<typename T>
class inner_array_set : public inner_set<T>
{
    public :
        T* a_values;
        int a_index;

        inner_array_set<T>();

        inner_array_set<T>(inner_set_5<T>*, T);

        virtual ~inner_array_set<T>();

        virtual inner_set<T>* add_element(T);

        virtual inner_set<T>* add_elements(T[]);

        virtual bool contains_element(T);

        virtual bool contains_all_elements(T[]);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);

        virtual inner_set<T>* retain_all_element(T[]);

        virtual int get_size();
};

#endif
