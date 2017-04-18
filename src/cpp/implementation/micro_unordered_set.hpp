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

                /* Operator */
                //virtual micro_set<T> operator=(micro_set<T>);

                /* Iterators */

                virtual void begin();

                virtual void end();

                virtual void rbegin();

                virtual void rend();

                virtual void cbegin();

                virtual void cend();

                virtual void crbegin();

                virtual void crend();

                /* Capacity */
                virtual bool empty() const;

                virtual int size() const;

                virtual int max_size() const;

                /* Modifiers */

                virtual void insert(T);

                virtual void erase(T);

                virtual void swap();

                virtual void clear();

                virtual void emplace();

                virtual void emplace_hint();

                /* Observers */ //TODO

                //virtual key_compare key_comp() const;

                //virtual value_compare value_comp() const;

                /* Operations */

                //virtual iterator_inner_set<T>* find(const T*) const;

                //virtual size_type count(const T*) const;

                virtual void lower_bound();

                virtual void upper_bound();

                virtual void equal_range();

        		/* Allocator */

                virtual void get_allocator();
        };

        #endif
