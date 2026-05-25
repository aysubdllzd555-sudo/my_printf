# Welcome to My Printf
***

## Task

In this project, the goal is to replicate the functionality of the standard `printf` function from the C library. I implemented a custom clone called `my_printf` which formats and prints data to the standard output. This project focuses on understanding variadic functions in C using the `<stdarg.h>` library, handling data types, managing low-level memory representation, and formatting output without using high-level ready-made library functions.
The function handles the following important formatting concepts:
ex00: printed single characters using `%c`
ex01: printed strings of characters using `%s`
ex02: printed signed integers and decimals using `%d` and `%i`
ex03: printed unsigned octal numbers using `%o`
ex04: printed unsigned decimal numbers using `%u`
ex05: printed unsigned hexadecimal numbers (lowercase) using `%x`
ex06: printed memory addresses / pointer values using `%p`

## Description
To solve this project, I structured the C files by writing low-level helper algorithms instead of relying on standard utility helper methods. I used the `write` system call as the foundational block to implement `my_putchar` and `my_putstr`. For managing multiple optional arguments dynamically, I utilized `va_list`, `va_start`, `va_arg`, and `va_end`.
To handle numbers in different numerical bases, I implemented a robust, non-recursive, iterative algorithm that converts decimals into hexadecimal, octal, and unsigned decimal representations using custom arrays and loops. The program safely handles edge cases, such as extreme values like the minimum possible integer (`-2147483648`), empty string pointers (`NULL`), and standard pointer address prefixes like `0x` or `(nil)` variations, matching the official platform behaviors perfectly.

## Installation
No installation is needed to run this project standalone. You only need a standard C compiler such as GCC or Clang installed on your local environment or within the platform sandbox container. Simply include the `my_printf.c` file or compiled source components into your project directory alongside your main entry file.

## Usage
To use this function, declare the `my_printf` prototype inside your main code files or include its header file. You can then invoke it exactly like the standard C printf function by passing a formatted string containing conversion specifiers followed by your corresponding variables. 

For compiling and checking the behavior, run your project through the compiler in your workspace terminal to link the object output files. You can observe the exact output characters and return size counts directly within the standard terminal shell logs.
```
./my_project my_printf.c
```

### The Core Team

abdullaz_a
<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
