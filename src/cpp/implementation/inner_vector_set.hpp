#ifndef INNER_VECTOR_SET_HPP
#define INNER_VECTOR_SET_HPP

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>


#include "inner_set.hpp"

using namespace std;

template<typename T>
class inner_vector_set : virtual public inner_set<T>
{
    private :
      vector<T>* a_values;

    public :
        inner_vector_set<T>();

        virtual ~inner_vector_set<T>();

        virtual inner_set<T>* add_element(T);
        virtual inner_set<T>* add_all_elements(inner_set<T>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T>*);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);
        virtual inner_set<T>* remove_all_elements(inner_set<T>*);

        virtual inner_set<T>* retain_all_elements(inner_set<T>*);

        virtual inner_set<T>* add_and_propagate(T, micro_set<T>*);
        virtual inner_set<T>* add_all_and_propagate(inner_set<T>*, micro_set<T>*);
        virtual inner_set<T>* add_all_and_propagate_reverse(inner_set<T>*, micro_set<T>*);

        virtual int get_size();
};

#endif
