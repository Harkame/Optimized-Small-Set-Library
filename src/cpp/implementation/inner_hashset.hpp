#ifndef INNER_HASHSET_HPP
#define INNER_HASHSET_HPP

#include <cstddef>
#include <iostream>
#include <set>

#include "inner_set.hpp"
#include "inner_array_set.hpp"

using namespace std;

template<typename T>
class inner_hashset : public inner_set<T>
{
    public :
        set<T>* a_values;


        inner_hashset<T>();

        inner_hashset<T>(T, T, T, T, T, T, T, T, T, T);

        inner_hashset<T>(T);

        virtual ~inner_hashset<T>();

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
