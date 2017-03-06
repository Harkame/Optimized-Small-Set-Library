#ifndef INNER_SET_1_H
#define INNER_SET_1_H

#include "inner_set.hpp"
#include "inner_set_0.hpp"
#include "inner_set_2.hpp"

using namespace std;

template<typename T>
class inner_set_1 : public inner_set<T>
{
    private :
        T** a_values;

    public :
        inner_set_1<T>();

        inner_set_1<T>(T*);

        virtual ~inner_set_1<T>();

        virtual inner_set<T>* add_element(T*);

        virtual inner_set<T>* add_elements(T**);

        virtual bool contains_element(T*);

        virtual bool contains_all_elements(T*);

        virtual T* get_element(int);

        virtual inner_set<T>* remove_element(T*);

        virtual inner_set<T>* retain_all_element(T**);

        virtual  int get_size();
};

#endif