#include <algorithm>
#include <iostream>
#include <vector>

//modify search by using lamda expression and sort also using lamda expression and measure time taken.


class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Define the comparison operator for sorting
    bool operator<(const Complex& obj) {
        if (this->real == obj.real) {
            return this->imag < obj.imag;
        }
        return this->real < obj.real;
    }
};

int main() {
    std::vector<Complex> vec = {
        {1, 2}, {3, 1}, {2, 2}, {1, 3}, {2, 1}
    };

    // Sort the vector using the default comparison operator
    std::sort(vec.begin(), vec.end());

    std::cout << "Sorted complex numbers (real, imag):" << std::endl;
    for (const auto& num : vec) {
        std::cout << "(" << num.real << ", " << num.imag << ")" << std::endl;
    }

    // Search for a specific complex number (e.g., {2, 2})
    Complex target(2, 2);
    auto it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        std::cout << "Found: (" << it->real << ", " << it->imag << ")" << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
