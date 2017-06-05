#ifndef INNER_SET_0_HPP
#define INNER_SET_0_HPP

#include "inner_set_1.hpp"

using namespace std;

template<typename T, int p_to_up>
class inner_set_0 : virtual public inner_set<T, p_to_up>
{
    friend class inner_set_1<T, p_to_up>;
    private :
        struct values
        {

        } a_values;

        inner_set_0<T, p_to_up>();

        virtual ~inner_set_0<T, p_to_up>();

        virtual inner_set<T, p_to_up>* add_element(T);
        virtual inner_set<T, p_to_up>* add_element_array(T);
        virtual inner_set<T, p_to_up>* add_all_elements(inner_set<T, p_to_up>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* copy();

        virtual T get_element(int);

        virtual inner_set<T, p_to_up>* remove_element(T);
        virtual inner_set<T, p_to_up>* remove_all_elements(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* retain_all_elements(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* add_and_propagate(T, micro_set<T, p_to_up>*);
        virtual inner_set<T, p_to_up>* add_all_and_propagate(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);
        virtual inner_set<T, p_to_up>* add_all_and_propagate_reverse(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);

        virtual int get_size();

        inner_set<T, p_to_up>& operator=(const inner_set<T, p_to_up>&){};

    public:
        static inner_set_0<T, p_to_up>* EMPTY;
};

#endif
