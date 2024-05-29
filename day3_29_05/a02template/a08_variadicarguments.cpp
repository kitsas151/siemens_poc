#include <iostream>

// Base case: function to end the recursion

/*

An ellipsis is used in two ways by variadic templates. 
To the left of the parameter name, it signifies a parameter 
pack, and to the right of the parameter name, 
it expands the parameter packs into separate names.

*/


#if 0
void print() {
    std::cout << "End of arguments." << std::endl;
}


// Recursive variadic function template
template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << std::endl;
    print(args...); // Recursively call print with the remaining arguments
}

int main() {
    print(1, 2.5, "Hello, world!", 'A');
    return 0;
}

/*
The print() function with no arguments serves as the base
 case to end the recursion. When the variadic template 
 function has no more arguments to process,
  this function is called.
Recursive Function Template:

The print function template takes at least one argument
 (first) and a parameter pack (args...).
It prints the first argument and then 
recursively calls itself with the remaining 
arguments (args...).


*/

#endif


#if 0
#include <iostream>

// Variadic function template with a fold expression to sum integers
template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

/*
Fold expression

A fold expression has the following components:
A set of parentheses ( ).
An expression involving a parameter pack.
A binary operator that combines the elements of the parameter pack.
The instantiation of a fold expression expands the expression as follows:

If you have a parameter pack Args, the fold expression (Args + ...) would apply the + operator to all the elements in the pack.

*/

int main() {
    int result = sum(1, 2, 3, 4, 5);
    std::cout << "Sum: " << result << std::endl;
    return 0;
}

#endif


#if 1

#include <iostream>
using namespace std;

// Variadic function template that takes variable number of arguments and prints all of them
template <typename... Types>
void print(Types... args) {
    // Using a fold expression to print all arguments
    ((cout << args << endl), ...);
}

int main() {
    print(1, 2, 3.14, "Pass me any number of arguments", "I will print");
    return 0;
}



#endif

#if 1


#include <iostream>

// Base case: function to end the recursion and return 0
template<typename T>
T sum(T value) {
    return value;
}

// Recursive variadic function template
template<typename T, typename... Args>
T sum(T first, Args... args) {
    std::cout << __PRETTY_FUNCTION__ <<std::endl;    
    return first + sum(args...); // Recursively sum the arguments
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4.5) << std::endl; // Output: 10.5
    return 0;
}


/*

Base Case:

The sum function with a single argument returns that argument.
 This serves as the base case to end the recursion.
Recursive Function Template:

The sum function template takes at least one argument (first) and a parameter pack (args...).
It returns the sum of the first argument and the result of a recursive call to sum with the remaining arguments (args...).



*/


#endif


#if 0
//c++ 17  provides fold xpressions
//simpler and more concise way to handle variadic templates.
#include <iostream>

// Variadic template function using a fold expression
template<typename... Args>
auto sum(Args... args) {
    return (args + ...); // Fold expression to sum all arguments
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4.5) << std::endl; // Output: 10.5
    return 0;
}


#endif 

#if 0


#include <iostream>

// Base case: function to end the recursion and return the value
constexpr int sum() {
    return 0;
}

// Recursive variadic template function
template<typename T, typename... Args>
constexpr T sum(T first, Args... args) {
    return first + sum(args...);
}

int main() {
    constexpr int result = sum(1, 2, 3, 4, 5);
    std::cout << "Sum: " << result << std::endl; // Output: Sum: 15

    // Compile-time assert to check the result
    static_assert(sum(1, 2, 3, 4, 5) == 15, "Sum is incorrect");

    return 0;
}

#endif



#if 0
#include <iostream>

// Variadic template function using a fold expression
template<typename... Args>
constexpr auto sum(Args... args) {
    return (args + ...); // Fold expression to sum all arguments

    //C++ 17 features
    //The fold expression (args + ...) sums all the arguments 
    //in the parameter pack.
    //Fold expressions provide a way to apply a binary
    // operator to a parameter pack in a compact manner.
}

int main() {
    constexpr int result = sum(1, 2, 3, 4, 5);
    std::cout << "Sum: " << result << std::endl; // Output: Sum: 15

    // Compile-time assert to check the result
    static_assert(sum(1, 2, 3, 4, 5) == 15, "Sum is incorrect");

    return 0;
}

#endif



#if 0
#include <iostream>
#include <iostream>
#include <string>

// Base case: Function to end the recursion and handle no arguments
void log() {
    std::cout << std::endl;
}

// Variadic template function to handle multiple arguments
template<typename T, typename... Args>
void log(T first, Args... args) {
    std::cout << first << " ";
    log(args...); // Recursively call log with the remaining arguments
}

int main() {
    log("This", "is", "a", "test", "with", 5, "arguments.");
    log("Logging", "different", 123, "types", 4.56);
    return 0;
}

#endif


