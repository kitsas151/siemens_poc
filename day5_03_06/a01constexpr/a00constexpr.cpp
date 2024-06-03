#if 1
#include <iostream>

constexpr int product(int x, int y) {
    return x * y;
}

int main() {
    constexpr int result = product(10, 20);
    std::cout << "Product: " << result; // Output: 200
    return 0;
}

constexpr int product(int x, int y) {
    return x * y;
}

void f1()
{

int arr[product(2, 3)] = {1, 2, 3, 4, 5, 6};
std::cout << "Element at index 5: " << arr[5]; // Output: 6

}

#include <iostream>

constexpr double PI = 3.14159265359;

constexpr double ConvertDegreeToRadian(const double& dDegree) {
    return dDegree * (PI / 180);
}

int main() {
    auto dAngleInRadian = ConvertDegreeToRadian(90.0);
    std::cout << "Angle in radian: " << dAngleInRadian; // Output: 1.5708
    return 0;
}

/*


They should contain only one return statement (C++11), but C++14 allows more than one statement.
They can refer only to constant global variables.
They can call only other constexpr functions (not simple functions).
They should not be of void type1.

*/




#endif