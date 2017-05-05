#ifndef INNER_SET_1_HPP
#define INNER_SET_1_HPP

#include "inner_set.hpp"

using namespace std;

template<typename T>
class inner_set_1 : public inner_set<T>
{
    public :
        struct values
        {
             T element_1;
        } a_values;

        inner_set_1<T>();
        inner_set_1<T>(T);

        virtual ~inner_set_1<T>();

        virtual inner_set<T>* add_element(T);
        virtual inner_set<T>* add_all_elements(inner_set<T>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T>*);

        virtual inner_set<T>* copy();

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
