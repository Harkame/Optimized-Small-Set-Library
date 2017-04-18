#ifndef inner_TREE_SET_HPP
#define inner_TREE_SET_HPP


#include "inner_set.hpp"

#include "inner_array_set.hpp"

#include <set>


using namespace std;

template<typename T>
class inner_tree_set : public inner_set<T>
{
    public :
        set<T>* a_values;

        inner_tree_set<T>();

        inner_tree_set<T>(inner_array_set<T>*, T);

        virtual ~inner_tree_set<T>();

        virtual inner_set<T>* add_element(T);
        virtual inner_set<T>* add_all_elements(inner_set<T>*);

        virtual bool contains_element(T);
        virtual bool contains_all_elements(inner_set<T>*);

        virtual T get_element(int);

        virtual inner_set<T>* remove_element(T);
        virtual inner_set<T>* remove_all_elements(inner_set<T>*);

        virtual inner_set<T>* retain_all_element(inner_set<T>*);

        virtual int get_size();
};

#endif
