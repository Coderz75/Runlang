#ifndef RSL_POINTERS_H
#define RSL_POINTERS_H

#include <iostream>
#include "../rsl.h"
#include "exceptions.h"
template <class T>
class ptr {
    int* pointer; // Actual pointer
public:
    // Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/
    // for use of explicit keyword
    explicit ptr(int* p = NULL) { pointer = p; }
 
    // Destructor
    ~ptr() { delete (pointer); }
 
    // Overloading dereferencing operator
    int& operator*() { return *pointer; }
};

#endif