

/*
In C++, decltype is a keyword used to determine the type of an expression at
 compile-time. On the other hand, 
 declval is a utility function provided by the <utility> header
  that allows you to obtain a reference to an object of a
   given type without the need to create an
    instance of that type.
    
     It is commonly used in contexts where you need to
      specify a type, such as when dealing 
      with decltype expressions in decltype specifier.

*/

#if 0

/*
decl type

Converts any type T to a reference type, making it possible to use member 
functions in the operand of the decltype specifier without 
the need to go through constructors.

std::declval is commonly used in templates where acceptable template parameters may
 have no constructor in common, but have the same member function
 whose return type is needed.

*/
#include <iostream>
#include <utility>
 
struct Default
{
    int foo() const { return 1; }
};
 
struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};
 
int main()
{
    //remember all these things are related to compile time only and not runtime.


    //here decl tpe is working becuase default constructor is there
    decltype(Default().foo()) n1 = 23;                   // type of n1 is int
//  decltype(NonDefault().foo()) n2 = n1;               // error: no default constructor
    decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
    
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n';
}

#endif

#if 1

#include <iostream>
#include <utility>

struct A {
    virtual int value() = 0;
};

class B : public A {
    int val_;
public:
    B(int i, int j) : val_(i * j) {}
    int value() { return val_; }
};

int main() {
    // Using decltype with std::declval
    decltype(std::declval<A>().value()) a; // Declares a variable of the return type of A::value()
    decltype(std::declval<B>().value()) b; // Declares a variable of the return type of B::value()

    // Note: We don't need to create actual instances of A or B!

    std::cout << "Type of 'a': " << typeid(a).name() << std::endl;
    std::cout << "Type of 'b': " << typeid(b).name() << std::endl;

    return 0;
}


#endif