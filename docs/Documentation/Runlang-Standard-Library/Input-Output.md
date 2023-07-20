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