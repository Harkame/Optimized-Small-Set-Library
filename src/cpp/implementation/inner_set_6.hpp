#ifndef INNER_SET_6_HPP
#define INNER_SET_6_HPP

#include "inner_set.hpp"
#include "inner_set_4.hpp"

using namespace std;

template<typename T>
class inner_set_6 : public inner_set<T>
{
    public :
        struct a_values
        {
             T element_1;
             T element_2;
             T element_3;
             T element_4;
             T element_6;
        } a_values;

        inner_set_6<T>();
        inner_set_6<T>(T , T , T , T , T);
        inner_set_6<T>(inner_set_5<T>*, T);

        virtual ~inner_set_6<T>();

        virtual inner_set<T>* add_element(T);
        virtual inner_set<T>* add_all_elements(inner_set<T>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T>*);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);
        virtual inner_set<T>* remove_all_elements(inner_set<T>*);

        virtual inner_set<T>* retain_all_elements(inner_set<T>*);

        virtual int get_size();
};

#endif
