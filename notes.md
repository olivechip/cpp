# C++ Notes

## Input/Output

* **iostream:** Library for input/output operations.
    * **std::cout:**  Character output (printing to console).
    * **std::cin:** Character input (reading from keyboard).
    * **std::getline(std::cin, variable_name):** Reads a whole line of input, including spaces.
    * **std::ws:**  Whitespace manipulator (often used with `getline` to ignore leading whitespace).
        ```c++
        getline(std::cin >> std::ws, variable_name); 
        ```

## Standard Namespace

* **std:** Short for "standard,"  a namespace that contains common C++ elements (like `cout`, `cin`, `string`).

## Math Functions

* **cmath:** Library with additional math functions.
    * **pow(x, y):**  x raised to the power of y (x<sup>y</sup>).
    * **sqrt(x):** Square root of x.
    * **abs(x):** Absolute value of x.
    * **round(x):** Rounds x to the nearest integer.
    * **ceil(x):** Rounds x up to the nearest integer.
    * **floor(x):** Rounds x down to the nearest integer.
* **max(number1, number2):** Returns the larger of two numbers.
* **min(number1, number2):** Returns the smaller of two numbers.

## Data Types

* **int:** Integer (whole numbers).
* **boolean:** True or false.
* **double:** Floating-point number (with decimals).
* **char:** Single character.
* **string:**  Sequence of characters (needs `#include <string>` and the `std::string` type).

## Variables

* **namespace:**  Used to organize code and prevent naming conflicts.
* **typedef:** (Legacy) Creates an alias for a data type.
* **using:** (Modern) Preferred way to create type aliases.  Use `_t` suffix when aliasing.
    ```c++
    typedef std::string string_t;   // Old way
    using string_t = std::string;  // Modern way
    ```

## Type Conversion

* **(new_type) variable:**  Converts a variable to a different type.
    ```c++
    cout << (double) score; 
    ```

## Operators and Control Flow

* **Comparison operators:**  ( `==`, `!=`, `>`, `<`, `>=`, `<=` ) - Same as JS.
* **Conditionals:** (`if`, `else if`, `else`) - Same as JS.
* **Switch statement:** (`switch`, `case`, `break`, `default`) - Same as JS.
* **Ternary operator:** (`condition ? value1 : value2`) - Same as JS.
* **Logical operators:** (`&&`, `||`, `!`) - Same as JS.

## String Methods

* **string.length():** Returns the length of a string.
* **string.empty():** Checks if string is empty.
* **string.append(`newString`):** Concatenates `newString` to `string`.
* **string.at(`index`):** Returns `char` at index of string.
* **string.insert(`index`, `newString`):** Inserts `newString` at `index`.
* **string.find(`char`):** Returns index of char.
* **string.erase(`index1`, `index2`):** Erases `index1`(inc) - `index2`(exc).

## While Loops

- works the same way as JS

## Do While Loops

execute code block first THEN check condition

do {
    stuff
} while (condition);

# For Loops

- works the same way as JS, just declare data type

break, continue  - same as JS
break - stops the entire loop, continue - skips current iteration

# Nested Loops
- same as JS

# Random Numbers
srand and ran come from the <cstdlib>, but is pulled in from <iostream> now
srand(int seed) - takes a seed value as input
rand() - generates a random number based on the seed from srand

time() comes from <ctime> but is pulled in from <iostream> now
time(NULL) - gets the current time 

srand(time(NULL)) - often used to generate a random seed from current time
rand() % int - used to generate random number from 0 up to int, use +1 to include int

# Functions
  
function names must have the returning data type before it
ex: `int` functionName(){}, `boolean` functionName(){}

using `void` before a function - does not return a data type
ex: `void` functionName(){}

parameters to be used in a function must be declared with data type
ex: `int` addNums(`int` num1, `int` num2){}