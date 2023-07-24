layout: page
title: "Getting Started"
permalink: /getting-started

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