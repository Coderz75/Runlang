# RunLang

RunLang is held under the [GPL Generic Public v3 License](./LICENSE)

<img src="logo.jpg"
     alt="RunLang Logo"
     style="height: 400px;"/>

RunLang is a coding language that is based on c++. It is cross compatible with c++, and has a plethora of features so you can spend more time coding instead of screaming at why something doesn't work

## Table of Cometents
- [Download](#download)
- [Getting started](#start)
- [Documentation](#docs)

<h1 id = "download">Download</h1>

The only way to download RunLang at the moment is to clone the repo. (This may be subject to chain the the language grows)

<h3>Prerequisites</h3>

RunLang requires a linux based os, [git](https://git-scm.com/), [Python3](https://www.python.org/), and [g++](https://gcc.gnu.org/) to by installed on your system. Windows users may use [Windows Subsystem for Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/install) to use RunLang.


<h3>Steps to install</h3>

1. Navigate to the directory to which you want to install RunLang
2. Run `git clone https://github.com/Coderz75/RunLang.git`
3. Run `cd RunLang/run`
4. Run `./install.sh`
5. Your done! Now you can use the `startl` command to compile your RunLang scripts!

<h2 id = "start">Getting started</h2>

1. To get started, create a `main.run` file in your chosen directory
2. Type the following code into the file:
```cpp
    #source/rsl

    fn main(){
        print("Welcome to RunLang!");
    }
```
3. To compile, run `startl main.run`
4. To finish, run the outputed file, which in this case should be main: `./main`
5. To add input, you can use the input function:
```cpp
    #source/rsl

    fn main(){
        print("Welcome to RunLang!");
        var my_input = input("Enter something here> ");
        print(my_input);
    }
```
6. Happy Coding!

<h1 id = "docs">Documentation</h1>
One thing to note before using RunLang. It compiles directly into c++. Any errors shown will be errors in it's c++ version. The compiler will do it's best to convert those to something more like your program, however it cannot garuntee full conversion. Any overlaying libraries are written in c++, and thus are constricted to the rules of c++

<h2>Libraries:</h2>

- [RunLang Standard Library (rsl)](#rsl)

<h2 id = "rsl">RunLang standard library (rsl)</h2>

The RunLang standard library is well, RunLang's standard library. To add it, add this to the top of your `main.run` file:
```cpp
    #source/rsl
```

The rsl library has many features inside of it, which will be attempted to be documented below.

- [Input, Output (I/O)](#rsl_io)
- [Random](#rsl_random)

<h3 id = "rsl_io">Input, Output (I/O)</h3>

```cpp
void print(First arg ... Last arg);
```        
The rsl library uses the function `print` to output text to the console. It works similarly to python, as it it can accept a number of types:
> print("Hi"); //Output: Hi

> print(1); //Output: 1

All things put into print uses c++'s `std::cout` function to print. Simply put, any object with a proper conversion for the `<<` operator will be able to use the print function to output text to the console.

It additionally can except any number of arguments, which all could be different types, and which would be outputed with a space in between
>print("Hello","hi");  // Output: Hello hi

>print("Hello",1); // Output: Hello 1

The print function will automatically add the `\n` newline to everything printed. If you do not wish to start a new line after the print, you can put the keyword `noend` as an arg.
> print("Hello", noend) //Output: Hello (no new line created)

```cpp
rsl::str input(rsl::str ask = "");
```
The input function returns a `rsl::str` (RunLang string). It can take in an optional parameter, `ask`, which will output on the same line before the input will start
> var my_input = input("Enter your age: ") // Output: Enter your age: (now you may type)

> var my_input = input() // Output: __ (Nothingm, and you may type input)

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