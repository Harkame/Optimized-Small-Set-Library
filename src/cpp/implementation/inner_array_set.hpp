#ifndef INNER_ARRAY_SET_HPP
#define INNER_ARRAY_SET_HPP

#include "inner_set.hpp"

#include "inner_set_5.hpp"

//#include "inner_unordered_set.hpp"

using namespace std;

template<typename T>
class inner_array_set : public inner_set<T>
{
    public :
        T a_values [20];
        int a_index;

        inner_array_set<T>();

        inner_array_set<T>(inner_set_5<T>*, T);

        //inner_array_set<T>(inner_unordered_set<T>, T);

        virtual ~inner_array_set<T>();

        virtual inner_set<T>* add_element(T);
        virtual inner_set<T>* add_all_elements(inner_set<T>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T>*);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);
        virtual inner_set<T>* remove_all_elements(inner_set<T>*);

        virtual inner_set<T>* retain_all_element(inner_set<T>*);

        virtual inner_set<T>* add_and_propagate(T, micro_set<T>*);
        virtual inner_set<T>* add_all_and_propagate(inner_set<T>*, micro_set<T>*);
        virtual inner_set<T>* add_all_and_propagate_reverse(inner_set<T>*, micro_set<T>*);

        virtual int get_size();
};

#endif
