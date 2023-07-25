---
layout: page
title: "Exceptions"
permalink: /docs/rsl/exceptions
parent: "Runlang Standard Library"
---

### Exceptions

The rsl library contains it's own exception handling class. It can be called using the `raise()` function

```cpp
raise("Bad argument >:(");
```

It will throw an exception, which when printed to the console would output something similar to this: 
```
terminate called after throwing an instance of 'rsl::exception'
  what():  In file: /mnt/c/Users/scien/Documents/Code/Runlang/.__RUNCACHE__main.cpp
Line: 3
Hello!
Aborted
```