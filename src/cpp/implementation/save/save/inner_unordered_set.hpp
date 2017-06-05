#ifndef INNER_UNORDERED_SET_HPP
#define INNER_UNORDERED_SET_HPP

#include <unordered_set>

#include "inner_set.hpp"

#include "inner_array_set.hpp"

#include "inner_tree_set.hpp"

using namespace std;

template<typename T, int p_to_up>
class inner_unordered_set : virtual public inner_set<T, p_to_up>, virtual public unordered_set<T>
{
    public :
        inner_unordered_set<T, p_to_up>();

        inner_unordered_set<T, p_to_up>(inner_set<T, p_to_up>*);

        inner_unordered_set<T, p_to_up>(inner_tree_set<T, p_to_up>*, T);

        virtual ~inner_unordered_set<T, p_to_up>();

        virtual inner_set<T, p_to_up>* add_element(T);
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
};

#endif
