#if 1

#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for std::for_each

// Function to fill a container with elements of a given type
template <typename Container, typename T>
auto fillContainer(Container &c, const T& value) -> Container {
    std::for_each(c.begin(), c.end(), [&value](auto& element) {
        element = value;
    });
    return c;
}

int main() {
    // Example usage with std::vector
    std::vector<int> myVector(5); // Create a vector of size 5
    fillContainer(myVector, 42); // Fill vector with value 42

    // Example usage with std::list
    std::list<std::string> myList(3); // Create a list of size 3
    fillContainer(myList, "Hello"); // Fill list with "Hello"


    // Print the filled containers
    for (const auto& val : myVector) {
        std::cout << val << " ";
    }
    std::cout << "\n";


    for (const auto& str : myList) {
        std::cout << str << " ";
    }

    std::cout << "\n";

    return 0;
}

#endif