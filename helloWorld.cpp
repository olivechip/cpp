#include <iostream>
#include <cmath>

int main()
{
    using std::cout;
    using std::cin;

    
    return 0;
}

// iostream - library for input/output, needed for alot of methods

// STD class - part of iostream library, contains other classes and methods
// std - short for standard, similar to standard library prebuilt in c++
// cout - character out, allows printing
// cin - character in, allows user input
// getline(std::cin, variable_name) - gets user input as line, good for spaces
// ws - whitespace, removes any ws, used w/ getline
//          (getline(std::cin >> std::ws, variable_name))
// max(number, number) - returns largest
// min(number, number) - returns smallest

// Data types
// int - integer
// boolean - true/false
// double - number w/ decimal
// char - single character
// string - data type that is part of std, must be init with "std::string"

// Variables
// prefix "namespace" - allows for using same variable
// prefix "typedef" - a new identifier for existing data type, for readability
//          legacy now - replaced mostly w/ "using"
// prefix "using" - for assigning priority to variables or shortcuts
// if reassigning variable names, must end in "_t"
// typedef std::string string_t;  === using text_t = std::string;
// typedef int number_t;          === using number_t = int;

// Type Conversion
// types can be converted with (new_type) preceding the variable;
// ex: cout << (double) score;

// cmath - library for other math functions
// pow(x, y) = x^y
// sqrt(9) = 3
// abs(-10) = 10
// round(x) = rounds closest
// ceil(x) = rounds up
// floor(x) = rounds down

// Comparison operators - same as Javascript
// Conditionals - same as Javascript
// Switch, case, break, default - same as Javascript
// Ternary Operators - same as Javascript
// Logical operators && || ! - same as Javascript
