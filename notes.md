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

# Function Signatures

functions with same name must have diff params
can be combined into default arguments like JS

#variable scope
- same as js

:: scope resolution operator, use it in front of a scoped variable to access its global value

best to avoid global variables

cin.clear()
fflush(stdin)
used for clearing errors?

# Arrays

Declaration: **dataType arrayName[size] = {elements...};**
Access: **arrayName[index]** (starts at 0)
Size: **std::size(arrayName)** (C++17)
Looping:
Range-based: **for (elementType element : arrayName)**
Traditional: **for (int i = 0; i < std::size(arrayName); ++i)**
Passing to Functions: 
- Important: Pass array and size as separate parameters (size is often mandatory). **int sum(int nums[], int size){...}**
- Remember: Declare data types before the parameters in both the function definition and declaration (if present). 
- Executing the function does not require data types. **sum(numbers, size)**
Searching: Iterate and use conditionals.
Sorting: Implement sorting algorithms (e.g., bubble sort). 
**nested loops checking for i > i + 1, then swapping**
Filling Arrays: useful for pre-filling large arrays
**std::fill: std::fill(std::begin(arrayName), std::end(arrayName), value)**
Multidimensional: **dataType arrayName[dim1][dim2]... = { {...}, {...} };**
Memory Address: location in memory where data is stored
accessed w/ **&variable**
Pass By Value:
- Copies of the original values are passed to arguments.
- Pass the argument name with & to pass the memory address (pass by reference).
- **void swap(int &x, int &y){...}**
Const Parameter: 
precede paramter with 'const', makes them read-only
**void swap(const int &x, const int &y){...}**

# Pointer: variable that stores memory address of another variable
uses & for address-of and * for dereference
***pVariable = &variable** 
arrays are already memory addresses - no need to assign pointers
**nullptr** - represents a pointer pointing to nothing
- helpful to determine if an address was assigned to a pointer
- always point to a valid address or nullptr
Dynamic Memory ALlocation 
- assign pointer to null, reassign just the variable to **new** Array
- remember to **delete** the reference ex: `delete[] pGrades`
- useful when memory needed is unknown initially
Recursion
- same concept as JS
- compared to iterative, recursion is slower and and costly, possible stack overflow
Function Template
- describes what a function looks like, used to generate overloaded functions using diff data types, 
- declaration `template <typename T>`, definition `T max(T x, T y)`, or auto
- Example:
- `template <typename T, typename U>`
- `T max(T x, U y){...}` OR `auto max(T x, U y){...}`
Struct
- struture that groups related variables under 1 name, can be diff data types
- equivalent of obj and classes in JS, can be assigned defaults in struct
  
struct student {
    std::string name; 
    double gpa; 
    bool enrolled = true;
    char sex;
};
student student1;
student.name = "oliver";
student.gpa = 4.0;
student.enrolled = true;

Assining Struct to Functions
- pass-by-value: copies are made, more expensive
- use & if need to modify original struct
`void printCar(Car car){...}`

Enums (Traditional)
- Create named integer constants, effectively defining a new data type.
- Declare using `enum Name { /* enumerators */ };`
- Enumerators are implicitly convertible to integers.
- Can lead to potential type-safety issues and naming collisions.
Example:
enum TrafficLight { RED, GREEN, YELLOW }; 
TrafficLight light = RED; 

Enum Classes (C++ 11+)
- Preferred way to define enums in modern C++.
- Declare using `enum class Name { /* enumerators */ };` (or enum struct)
- Stronger type safety: No implicit conversion to integers.
- Scoped names: Access enumerators with :: (e.g., `Name::RED`).
- Prevents naming collisions and promotes clearer code.
- helper function needed to extract Enum values
Example:
enum class TrafficLight { RED, GREEN, YELLOW };
TrafficLight light = TrafficLight::RED;