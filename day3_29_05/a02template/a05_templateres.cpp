#include <iostream>
#include <type_traits>

// Function template with SFINAE to restrict to integral types
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printValue(T value) {
    std::cout << "The value is: " << value << std::endl;
}

//We use std::enable_if and std::is_integral to enable
// or disable the function template based on whether the type
// is integral.

//If std::is_integral<T>::value is true, the first version of
// printValue is enabled.




// Overload to handle non-integral types and give a compile-time error
template<typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
printValue(T value) {
    static_assert(std::is_integral<T>::value, "The value must be an integral type");
}


int main() {
    printValue("hello");      // OK, 42 is an integral type
    printValue(3.14); // Compile-time error, 3.14 is not an integral type
    return 0;
}
