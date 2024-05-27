#include <iostream>
#include <type_traits>

#if 0
auto f()->int
{
    return 2;
}

auto add(int a, int b) -> int {
    return a + b;
}


//delltype(auto) multiply(T1 a, T2 b) 
template <typename T1, typename T2>
auto multiply(T1 a, T2 b) -> decltype(a * b) {
    return a * b;
}


auto g() { return 0.0; };
auto h();// ok return type will be deduced
//when defined


auto f3() -> int
{
    return 4;
}

void anotherscnearios()
{
auto x = 5; // OK: x has type int
const auto *v = &x, u = 6; // OK: v has type const int*, u has type const int
std::cout << typeid(v).name() << "\n";
static auto y = 0.0; // OK: y has type double
auto (*fp)() ->auto = f3; // OK: the “auto” in the trailing return type
                          // can be deduced from f
}





int main()
{
    auto x =3;
    std::cout << "Sum: " << add(2, 3) << std::endl;
    std::cout << "Product: " << multiply(3, 4.5) << std::endl;
    return 0;

}




#endif

#if 1

int main()
{
        int k=3;
        const int &l =k;
        auto  i = l;
        static_assert(std::is_same_v<decltype(i),const int &>);
        //static_assert(std::is_same_v<decltype(i),const int &>);
        std::cout << "is it working";

}

#endif

#if 0
#include <iostream>

// Function definition
auto f() -> int {
    return 42;
}

// Pointer to function declaration and initialization
auto (*fp)() -> auto = f;

int main() {
    // Calling the function through the pointer
    std::cout << "The value is: " << fp() << std::endl;  // Output: The value is: 42
    return 0;
}

/*

auto (*fp)(): fp is a pointer to a function taking no arguments.
-> auto: 
The return type is deduced to be the same as f, which is int.
= f: Initializes fp to point to f.

*/


#endif


#if 0

int main()
{

int a[2] = {1, 2};

std::cout << typeid(a).name()  << "\n ";
 
auto [x, y] = a;   
                   
auto& [xr, yr] = a;  // then x refers to e[0], y refers to e[1]

xr=4;

std::cout << xr << "  "<< yr;

}

#endif


#if 0

#include <initializer_list>

int main()
{
    // std::initializer_list<int>
    auto A = { 1, 2 };

    // std::initializer_list<int>
    auto B = { 3 };

    // int
    auto C{ 4 };

    // C3535: cannot deduce type for 'auto' from initializer list'
    auto D = { 5, 6.7 };

    // C3518 in a direct-list-initialization context the type for 'auto'
    // can only be deduced from a single initializer expression
    auto E{ 8, 9 };

    return 0;
}

#endif

#if 0


#include <iostream>

using namespace std;




/*

 




*/

int main( )
{
    int count = 10;
    int& countRef = count;
    auto myAuto = countRef;// reference not deduced
    myAuto =23; // 
    std::cout <<  count;
    auto &temp = countRef;
    temp =23;
    std::cout << "count  " << count  << "\n";

    const int *p =nullptr;
    const int i{};
    auto ptrcopy = p;
    //decltype(auto)
    auto valcopy =i;
    ptrcopy =&i;    
    valcopy=45;






    

#if 0
    countRef = 11;
    cout << count << " ";

    myAuto = 12;
    cout << count << endl;

#endif
}

#endif


