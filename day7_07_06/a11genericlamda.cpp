#if 1

#include <iostream>

int main() {
    // Generic lambda to compute the sum of two values
    auto sum =  [](auto a, auto b){
        return a + b;
    };

    std::cout << "Sum of integers: " << sum(1, 6) << "\n";
    std::cout << "Sum of doubles: " << sum(1.0, 5.6) << "\n";
    //std::cout << "Concatenated strings: " << sum("Geeks", "ForGeeks") << "\n";

    return 0;
}


#endif