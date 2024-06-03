#if 0

#include <iostream>

using namespace std;


int main()
{
int x=42;
decltype(x) y;// make y also as an int

const int e = 10;
decltype(e) i{0}; // i has the same type as e (const int)





return 0;
}

#endif

#if 0

#include <iostream>

int main() {
    // Ensure that the size of an integer is greater than or equal to 4 bytes
    static_assert(sizeof(int) >= 4, "Size of integer must be greater than or equal to 4 bytes");


    //direct initalization

    int x = 42; // Initialize 'x' with the value 42

    //Uniform Initialization (C++11 and later):

    int y{10}; // Initialize 'y' with the value 10

    //
    char letter('A'); // Initialize 'letter' with the character 'A'

    int a = 5, b = 10; // Initialize 'a' with 5 and 'b' with 10
    



    // Rest of your code...
    return 0;
}



#endif