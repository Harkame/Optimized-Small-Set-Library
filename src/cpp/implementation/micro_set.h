#ifndef _MICROSET_H
#define _MICROSET_H

#include <set>

#include "inner_set.h"
#include "inner_set_0.h"

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
        virtual bool empty();

        virtual int size();

        virtual int max_size();

        /* Modifiers */

        virtual void insert();

        virtual void erase();

        virtual void swap();

        virtual void clear();

        virtual void emplace();

        virtual void emplace_hint();

        /* Observers */

        virtual void key_comp();

        virtual void value_comp();

        /* Operations */

        virtual void fin();

        virtual void count();

        virtual void lower_bound();

        virtual void upper_bound();

        virtual void equal_range();

		/* Allocator */

        virtual void get_allocator();
};

#endif
