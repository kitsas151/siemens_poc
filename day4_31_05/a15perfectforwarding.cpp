#include <iostream>
#include <utility>

#if 0

// Display function overloads
void Display(int& i) {
    std::cout << i << " int& called" << std::endl;
}

void Display(int&& i) {
    std::cout << i << " int&& called" << std::endl;
}

// Wrapper function using perfect forwarding
template <class T>
void DisplayWrapper(T&& t) {
    Display(std::forward<T>(t));
}

int main() {
    int x = 5;

    // Example 1: Passing an rvalue (prvalue)
    //DisplayWrapper(5); // Output: int&& called

    // Example 2: Passing an lvalue
    //DisplayWrapper(x); // Output: int& called

    Display(5);
    Display(x);



    return 0;
}

#endif

#if 1

#include <iostream>
#include <utility> // for std::forward

class Wrapper {
public:
    explicit Wrapper(int value) : data(value) {}

    // Display function with perfect forwarding
    template <typename T>
    void Display(T&& value) {
        std::cout << "Wrapped value: " << std::forward<T>(value) << std::endl;
    }

private:
    int data;
};

int main() {
    Wrapper wrapper(42);

    int x = 10;
    wrapper.Display(x); // Pass an lvalue
    wrapper.Display(20); // Pass an rvalue

    return 0;
}


#endif

