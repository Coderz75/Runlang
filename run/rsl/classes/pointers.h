#ifndef RSL_POINTERS_H
#define RSL_POINTERS_H

#include <iostream>
#include "../rsl.h"
#include "exceptions.h"
template <class T>
class ptr {
    T* x; // Actual pointer
public:

    explicit ptr(T* p = NULL) {
        x = p; 

    }
    #ifndef __GNUC__
    ~ptr() {if (x!=NULL) delete (x); x = NULL;}
    #endif

    T& operator*() {return *x;}
 

    T* operator->() {return x;}
    
    operator auto () const{return x;}
};

#endif