#ifndef MICRO_unordered_SET_HPP
#define MICRO_unordered_SET_HPP

#include <map>

#include "inner_set_0.hpp"
#include "inner_set_1.hpp"
#include "inner_set_2.hpp"
#include "inner_set_3.hpp"
#include "inner_set_4.hpp"
#include "inner_set_5.hpp"

#include "inner_array_set.hpp"
#include "inner_unordered_set.hpp"


using namespace std;

template<typename T>
class micro_unordered_set : public set<T>
{
    private :
        inner_set<T>* a_inner_set;

    public :
        micro_unordered_set();

        virtual ~micro_unordered_set();

        virtual iterator_inner_set<T>* begin();

        virtual iterator_inner_set<T>* end();

        virtual iterator_inner_set<T>* find(T);

        virtual bool empty() const;

        virtual int size() const;

        virtual int max_size() const;

        virtual void insert(T);

        virtual void erase(T);

        virtual void clear();
  };

        #endif
