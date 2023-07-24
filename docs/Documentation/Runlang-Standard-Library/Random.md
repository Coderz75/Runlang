---
layout: page
title: "Random"
permalink: /docs/rsl/random
---
<h3 id = "rsl_random">Random</h3>

Random is a class written in c++ to make random numbers

```cpp
int Random.rint();
int Random.rint(int min,int max);
```

The random integer function in the random class is pretty straightforward. It can accept either none or 2 arguments, min and max. If it is none, then the max and min numbers will be automatically set to the max and min number, defined in `#include <climits>`, and is dependable on exactly which compiler is runlang compiling into.

> print(Random.rint()) //Output: -1.07374e+09 (example output)

> print(Random.rint(3,5)) //Output: 4 (example output)

```cpp
float Random.rfloat(precision = 2);
float Random.rfloat(int min, int max, precision = 2);
```

Like it's integer counterpart, rfloat return a random float. There is an extra variable involved, which is precision. Precision means the amount of decimal places should the outputed number have. So a number with precision 2 could be `5.43` while a number of precision 4 could possibly be `4.4523`. If a min and max is not given, it will again use the min and max defined in `#include <climits>`
> print(Random.rfloat()) //Output: 349879487.29 (example output)

> print(Random.rfloat(3)) //Output: 57367483.483 (example output)

> print(Random.rfloat(0,5)) //Output: 3.45 (example output)

> print(Random.rfloat(0,5,3)) //Output: 4.438 (example output)