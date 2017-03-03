#ifndef MICROSET_H
#define MICROSET_H

#include <map>
#include <set>

#include "inner_set.hpp"
#include "inner_set_0.hpp"

using namespace std;

template<typename T>
class micro_set : public set<T>
{
    private :
        inner_set<T>* a_inner_set;

    public :
        micro_set();

        virtual ~micro_set();

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

        virtual void insert();

        virtual void erase();

        virtual void swap();

        virtual void clear();

        virtual void emplace();

        virtual void emplace_hint();

        /* Observers */ //TODO

        //virtual key_compare key_comp() const;

        //virtual value_compare value_comp() const;

        /* Operations */

        //virtual iterator find(const T*) const;

        //virtual size_type count(const T*) const;

        virtual void lower_bound();

        virtual void upper_bound();

        virtual void equal_range();

		/* Allocator */

        virtual void get_allocator();
};

#endif
