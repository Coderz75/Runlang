---
layout: page
title: "Pointers"
permalink: /docs/rsl/pointers
parent: "Runlang Standard Library"
---

### Pointers

The rsl library has it's own smart pointer class. A smart pointer is a pointer that will delete itself automatically once it goes out of scope, like a regular variable. 

```cpp
class ptr<class T>;
```
To use pointer, it acts like a regular variable:
```cpp
ptr<int> p = new int();
// TO access the actual value, just use the dereference operator like in c++ (*)
*p = 4;
```
It is recomended to use runlang smart pointers instead of regular pointers, as they will automatically delete themselves when they leave scope. If you want to delete them earlier, you may use the `clear()` function
```cpp
void ptr.clear()
```
which automatically clears the pointer.

As a side note, as RunLang runs in c++, its recomended to use the reference operator instead (`&`). They can be used to pass references into functions:
```cpp
fn hi(string& e){
    //do something with the e reference
    e = "Hi"; // The value of e (the one passed into the function) is now "hi"
}
```