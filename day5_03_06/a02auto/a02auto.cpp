#include <iostream>

#if 1

template <typename T1, typename T2>
auto product(T1 a, T2 b) -> decltype(a * b) {
    return a * b;
}

int main() {
    int x = 5;
    double y = 3.5;
    std::cout << "Product: " << product(x, y) << std::endl;
    return 0;
}

#endif

#if 0

#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}


#endif


#if 0
#include <utility>

/*
Problem 4: Complex Type with decltype
Write a function that takes a pair of integers and returns their sum. Use decltype to deduce the return type. Also, use auto to declare the variables inside the function.
*/

auto sum_pair(std::pair<int, int> p) -> decltype(p.first + p.second) {
    return p.first + p.second;
}

int main() {
    std::pair<int, int> p = {10, 20};
    std::cout << "Sum: " << sum_pair(p) << std::endl;
    return 0;
}

#endif

#if 0
#include <iostream>

/*

Problem 5: Using auto with Lambda Expressions
Write a lambda expression that captures two
 variables by reference, modifies them, and
  prints their values. Use auto to declare the
   lambda.


*/

int main() {
    int a = 10, b = 20;
    auto lambda = [&a, &b]() {
        a += 5;
        b += 10;
        std::cout << "Inside lambda: a = " << a << ", b = " << b << std::endl;
    };
    lambda();
    std::cout << "Outside lambda: a = " << a << ", b = " << b << std::endl;
    return 0;
}

#endif


#if 0

/*


Declare a function pointer using auto and
 decltype for a function that takes two
  integers and returns their sum.

*/

#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    auto funcPtr = add;
    std::cout << "Sum: " << funcPtr(10, 20) << std::endl;

    // Using decltype to declare another function pointer
    decltype(add) funcPtr2 = add;
    std::cout << "Sum: " << funcPtr2(30, 40) << std::endl;

    return 0;
}

#endif



