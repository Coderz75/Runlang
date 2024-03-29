/*
    Runlang. A programming language that brings the ease of python to the speed to c++
    Copyright (C) 2023  Nuaym Syed

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
#ifndef RSL_POINTERS_H
#define RSL_POINTERS_H

#include <iostream>
#include "../rsl.h"
#include "exceptions.h"
template <class T>
class ptr {
    T* pointer; 
public:

    explicit ptr(T* p = NULL) { pointer = p; }

    // Destructor
    ~ptr() { if (pointer != NULL) delete (pointer); }
 
    // Dereference operator
    T& operator*() { return *pointer; }

    void clear(){
        delete (pointer);
    }
};

#endif