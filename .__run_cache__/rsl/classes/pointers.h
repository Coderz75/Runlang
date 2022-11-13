#ifndef POINTERS_H
#define POINTERS_H

#include <iostream>
#include "../rsl.h"
template <class T>
class ptr {
    T* x; // Actual pointer
public:

    explicit ptr(T* p = NULL) { x = p; }

    ~ptr() { delete x; }

    T& operator*() { return *x; }
 

    T* operator->() { return x; }
    
    operator auto () const{return x;}
};

#endif