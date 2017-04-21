#ifndef MICRO_tree_SET_HPP
#define MICRO_tree_SET_HPP

#include <map>
#include <set>

#include "inner_set_0.hpp"
#include "inner_set_1.hpp"
#include "inner_set_2.hpp"
#include "inner_set_3.hpp"
#include "inner_set_4.hpp"
#include "inner_set_5.hpp"

#include "inner_array_set.hpp"
#include "inner_tree_set.hpp"


using namespace std;

template<typename T>
class micro_tree_set
{
    private :
        inner_set<T>* a_inner_set;

    public :
        micro_tree_set();

        virtual ~micro_tree_set();

        virtual iterator_inner_set<T>* begin();

        virtual iterator_inner_set<T>* end();

//        virtual iterator_inner_set<T>* find(T);

        virtual bool empty() const;

        virtual int size() const;

        virtual int max_size() const;

        virtual void insert(T);

        virtual void erase(T);

        virtual void clear();

        virtual bool retain_all(micro_tree_set<T>);
};

        #endif
