---
layout: page
title: "Strings"
permalink: /docs/rsl/strings
parent: "Runlang Standard Library"
---

### Strings

Runlang has a build in string class that makes many simple operations much more easier
```cpp
class string(char*)
class string(std::string)
class string()
```
The string class takes in multiple constructors, so it can collect c, c++, and runlang strings. If you do not specify a value on initilization, then of course, the string will be empty

```cpp
string string.upper();
```
The `upper()` function returns a rsl string that is the original string but all uppercase.

It **does not** change the original string

>"hi".upper() // Returns: "HI"

```cpp
string string.lower();
```
The `lower()` function returns a rsl string that is the original string but all lowercase.

It **does not** change the original string
>"HI".lower() // Returns: "hi"

```cpp
std::vector<std::string>  string.split(std::string x = " ", int m = false);
```
The `split` splits the string into components, devided by `x`, `m` times. `x` is spaces by default.

`.split()` **does not** change the original string

> "Hello World".split() // Returns: {"Hello","World"}
> "Hello|World".split("|") // Returns: {"Hello","World"}

```cpp
bool string.isupper();
```
The `isupper`` function returns a bool, which would be true if the entire string is uppercase, and false if not

`.isupper()` **does not** change the original string

>"HI".isupper() // Returns: True
>"Hi".isupper() // Returns: False

```cpp
bool string.islower();
```
The `islower` function returns a bool, which would be true if the entire string is lowercase, and false if not

`.islower()` **does not** change the original string

>"hi".islower() // Returns: True
>"Hi".islower() // Returns: False

```cpp
string string.center(int s, rsl::string a = " ");
```
The `center` function returns a string of `s` length. It will fill the string with the charachter: `m`, which is by default, spaces. If the length of the string exceeds `s`, it will just return the original string

`.center()` **does not** change the original string
> "Hi".center(6) // Returns: "  Hi  "
> "Hi".center(6,"0") // Returns: "00Hi00"

```cpp
string string.swapcase();
```
The `swapcase()` function returns the a string with the cases swapped

`.swapcase()` **does not** change the original string

>"Hi".swapcase() // Returns "hI"

```cpp
bool string.startswith(rsl::string a, int b = 0, int c = a.length());
```
Startswith checks if the string starts with `a`, or from starting position `b`, and ends at position `c`.

`.startswith()` **does not** change the original string
>"Hello how is life".startswith("Hello") // True

```cpp
bool string.endswith(std::string suffix);
```
`endswith` checks if the string ends with `suffix`, and returns true if it is, else false

`.endswith()` **does not** change the original string
>"Hello how is life".endswith("Life") // True

```cpp
std::string string.cpp_str();
```
`.cpp_str()` returns an std::string, that is the c++ string, which may be usefull for cross compatibility
```cpp
char const string.c_str();
```
`.c_str()` returns a char const, which is the string for c, which may be usefull for backwards compatibility