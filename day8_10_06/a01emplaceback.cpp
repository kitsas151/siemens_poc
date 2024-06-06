#if 0

/*
Use push_back when you want to move an existing object into the vector.
Use emplace_back when you create a new temporary object and want to construct it directly in place within the container12.
*/

#include <iostream>
#include <vector>

struct MyObject {
    int value;
    MyObject(int val) : value(val) {}
};

int main() {
    std::vector<MyObject> myVec;
    myVec.emplace_back(42); // Constructs directly in place

    MyObject obj(42);
    myVec.push_back(obj); // Copies obj into the vector

    // Access the element
    std::cout << "Value in vector: " << myVec[0].value << std::endl;

    return 0;
}




#endif