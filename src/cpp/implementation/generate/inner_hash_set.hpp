#ifndef INNER_HASH_SET_HPP
#define INNER_HASH_SET_HPP

#include <cstddef>
#include <iostream>
#include <set>

#include "inner_set.hpp"
#include "inner_array_set.hpp"

using namespace std;

template<typename T>
class inner_hash_set : public inner_set<T>
{
    public :
        set<T>* a_values;


        inner_hash_set<T>();

        inner_hash_set<T>(T, T, T, T, T, T, T, T, T, T);

        inner_hash_set<T>(inner_array_set<T>*, T);

        virtual ~inner_hash_set<T>();

        virtual inner_set<T>* add_element(T);
        virtual inner_set<T>* add_all_elements(inner_set<T>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T>*);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);
        virtual inner_set<T>* remove_all_elements(inner_set<T>*);

        virtual inner_set<T>* retain_all_element(inner_set<T>*);

        virtual int get_size();
};

#endif
