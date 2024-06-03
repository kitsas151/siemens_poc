

#if 0

//Example 1: Ambiguous Type Deduction
auto x; // Error: cannot deduce type



/*

Conflicting Types in Initialization

*/
auto x = 5;
x = "hello"; // Error: conflicting types


#endif


#if 1


/*
In C++, function declarations with auto are 
not allowed, as they must specify the
 return type explicitly. Hence, the
  compiler will generate an error
   for this.

*/
auto foo();

int main()
{
    return 0;
}

#endif

#if 0

 //Using auto with Multiple Types in a
 // Single Statemen

 auto x = 5, y = "hello"; // Error: inconsistent deduction for 'auto'


#endif


#if 0

//Auto-Template Parameters 
//in a Function Declaration

template <auto x>
void foo() {}

int main() {
    foo<5>();   // Error: cannot deduce auto template argument from '5'
    return 0;
}



#endif


#if 0

/*

Using auto with Variable-Length Arrays (VLAs)

*/

int main() {
    int size = 10;
    auto arr[size]; // Error: size not a constant expression
    return 0;
}


#endif

#if 0

/*

Ambiguous Return Type Deduction in Template
 Functions

*/
template<typename T>
auto add(T a, T b) {
    if (std::is_same<T, int>::value)
        return a + b;
    else
        return a + b + 0.5; // Error: inconsistent return types
}

int main() {
    auto result = add(5, 6);
    return 0;
}

#endif
