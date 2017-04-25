#ifndef INNER_SET_0_HPP
#define INNER_SET_0_HPP

#include "inner_set.hpp"
#include "inner_set_1.hpp"

using namespace std;

template<typename T>
class inner_set_0 : public inner_set<T>
{
    public :
      struct values
      {

      } a_values;

        inner_set_0<T>();

        virtual ~inner_set_0<T>();

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
