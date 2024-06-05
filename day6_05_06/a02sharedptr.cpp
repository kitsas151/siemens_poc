#include <iostream>
#include <memory> // Include the <memory> header for shared_ptr

struct MyClass {
    int value;

    MyClass(int val) : value(val) {
        std::cout << "Constructing MyClass with value: " << value << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructing MyClass with value: " << value << std::endl;
    }
};

void f1(std::shared_ptr<MyClass> ptr2)
{

    ptr2->value=44;
    std::cout << "Value via ptr2: " << ptr2->value << std::endl;
    

}

int main() {
    // Create a shared_ptr to a dynamically allocated MyClass object
    
    {
    std::shared_ptr<MyClass> ptr1(new MyClass(3));

     f1(ptr1);
        // Create another shared_ptr pointing to the same object
    // Access the object via ptr2 (still valid)
    std::cout << "Value via ptr1 after reset: " << ptr1->value << std::endl;
    }
    std::cout  << "main function at work";
       return 0;
}

/*

Shared Ownership:
Use std::shared_ptr when you want shared ownership of a dynamically allocated resource.
Multiple shared_ptr instances can point to the same object, and the resource is automatically cleaned
 up when the last shared_ptr goes out of scope1.
Member Objects:
You can use std::shared_ptr to point to member objects while owning the object they belong to.
This is useful when you want to share ownership of a part of an object2.

*/
