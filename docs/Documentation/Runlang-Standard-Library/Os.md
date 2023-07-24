---
layout: page
title: "OS"
permalink: /docs/rsl/os
parent: "Runlang Standard Library"
---
<h3 id = "rsl_random">OS</h3>
OS is a class written in c++ in order to comunicate directly with the operating system.


```cpp
void os.exec(rsl::string command);
```
`os.exec()` has the same properties as they `system()` function in c++ and the `os.system()` function in python. Likewise, it takes a string as an input, then executes the string, the same way as if it was executed directly in the terminal.
> os.exec("ls");  // Lists all files in directory
> os.exec("cd ~"); // navigates to the home directory

>**Warning**
> The `os.exec` command runs the same way as the `system()` function in c++. Meaning, it is possible to run multiple commands in the same line with a semicolon (`;`), and hackers may use input to enter malicious commands into a system. Please remember to clean any data passed into the command (by for example limiting semicolons) in order to prevent such attacks from happening.