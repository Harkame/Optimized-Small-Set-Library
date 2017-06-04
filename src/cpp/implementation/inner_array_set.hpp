#ifndef INNER_ARRAY_SET_HPP
#define INNER_ARRAY_SET_HPP

#include "inner_set.hpp"
#include "inner_set_3.hpp"

using namespace std;

template<typename T, int p_to_up>
class inner_array_set : public inner_set<T, p_to_up>
{
    public :
        T a_values [20];
        int a_index;

          inner_array_set<T, p_to_up>();
          inner_array_set<T, p_to_up>(T);
          inner_array_set<T, p_to_up>(inner_set_1<T, p_to_up>*, T);
          inner_array_set<T, p_to_up>(inner_set_2<T, p_to_up>*, T);
          inner_array_set<T, p_to_up>(inner_set_3<T, p_to_up>*, T);
          inner_array_set<T, p_to_up>(inner_set<T, p_to_up>*);

        virtual ~inner_array_set<T, p_to_up>();

        virtual inner_set<T, p_to_up>* add_element(T);
        virtual inner_set<T, p_to_up>* add_all_elements(inner_set<T, p_to_up>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* copy();

        virtual T get_element(int);

        virtual inner_set<T, p_to_up>* remove_element(T);
        virtual inner_set<T, p_to_up>* remove_all_elements(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* retain_all_element(inner_set<T, p_to_up>*);

        virtual inner_set<T, p_to_up>* add_and_propagate(T, micro_set<T, p_to_up>*);
        virtual inner_set<T, p_to_up>* add_all_and_propagate(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);
        virtual inner_set<T, p_to_up>* add_all_and_propagate_reverse(inner_set<T, p_to_up>*, micro_set<T, p_to_up>*);

        virtual int get_size();
};

#endif
