// main.cpp
#include "a02math_operations.h"
#include "a03printer.h"
#include <string>


int main() {
    int result = add(10, 5);
    printMessage("Result of addition: " + std::to_string(result));

    result = subtract(10, 5);
    printMessage("Result of subtraction: " + std::to_string(result));

    return 0;
}
