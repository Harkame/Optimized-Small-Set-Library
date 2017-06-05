#ifndef INNER_SET_9_HPP
#define INNER_SET_9_HPP


#include "inner_set.hpp"
#include "inner_set_8.hpp"

using namespace std;

template<typename T, int p_to_up>
class inner_set_9 : public inner_set<T, p_to_up>
{
    public :
        struct values
        {
             T element_1;  T element_2;  T element_3;  T element_4;  T element_5;  T element_6;  T element_7;  T element_8;  T element_9;
        } a_values;

        inner_set_9<T, p_to_up>();
        inner_set_9<T, p_to_up>( T, T, T, T, T, T, T, T, T);
        inner_set_9<T, p_to_up>(inner_set_8<T, p_to_up>*, T);

        virtual inner_set<T, p_to_up>* copy();

        virtual ~inner_set_9<T, p_to_up>();

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T, p_to_up>*);

        virtual T get_element(int);

        virtual int get_size();

        virtual inner_set<T, p_to_up>* add_element(T);
        virtual inner_set<T, p_to_up>* add_all_elements(inner_set<T, p_to_up>*);


        virtual inner_set<T, p_to_up>* remove_element(T);
        virtual inner_set<T, p_to_up>* remove_all_elements(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* retain_all_elements(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* add_and_propagate(T, micro_set<T, p_to_up>*);
        virtual inner_set<T, p_to_up>* add_all_and_propagate(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);
        virtual inner_set<T, p_to_up>* add_all_and_propagate_reverse(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);
};

#endif
