#include <iostream>
#include <vector>

// Templated class
template <typename T>
class MyClass {
public:
    MyClass(T value) : data(value) {}

    // Forward declaration of the templated member function
    template <typename U>
    void PrintValue(U otherValue);

private:
    T data;
};

// Definition of the templated member function
template <typename T>
template <typename U>
void MyClass<T>::PrintValue(U otherValue) {
    std::cout << "Data: " << data << ", Other Value: " << otherValue << std::endl;
}

int main() {
    // Instantiate MyClass with int
    MyClass<int> intObj(42);
    intObj.PrintValue(10);  // Output: Data: 42, Other Value: 10

    // Instantiate MyClass with double
    MyClass<double> doubleObj(3.14);
    doubleObj.PrintValue(2.71);  // Output: Data: 3.14, Other Value: 2.71

    return 0;
}
