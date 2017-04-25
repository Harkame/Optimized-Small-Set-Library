#ifndef INNER_SET_2_HPP
#define INNER_SET_2_HPP

#include "inner_set.hpp"
#include "inner_set_1.hpp"

using namespace std;

template<typename T>
class inner_set_2 : public inner_set<T>
{
    public :
        struct values
        {
             T element_1;  T element_2;
        } a_values;

        inner_set_2<T>();
        inner_set_2<T>(T , T);
        inner_set_2<T>(inner_set_1<T>* , T);

        virtual ~inner_set_2<T>();

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
