

#include <iostream>
#include <chrono>
#include <thread>




#if 1

constexpr 
int square(int x) {
    for(int i=0; i<262144; i++);
    return x * x;
}



int main() {
    {

    auto start = std::chrono::high_resolution_clock::now();    
    constexpr
     int value = 5;
    constexpr
     int result = square(value); // Evaluated at compile time
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\n " << duration.count() << "milli seconds taken";
    }
  
    #if 0
    static_assert(result==25);
    std::cout << "Square of " << value << " is " << result << std::endl;

    #endif
    
    return 0;
}


#endif

#if 0


#include <iostream>

constexpr int arraySize(int size) {
    return size * 2;
}

int main() {
    constexpr int size = 5;
    int arr[arraySize(size)]; // Array size determined at compile time
    std::cout << "Array size: " << sizeof(arr) / sizeof(arr[0]) << std::endl;

    return 0;
}


#endif

#if 0

#include <iostream>

class Circle {
public:
    constexpr Circle(double r) : radius(r) {}

    constexpr double getArea() const {
        return pi * radius * radius;
    }

private:
    static constexpr double pi = 3.14159265358979323846;
    double radius;
};

int main() {
    constexpr Circle c(5.0); // Compile-time instantiation of Circle object
    constexpr double area = c.getArea();
    std::cout << "Area of circle with radius " << c.getRadius() << " is " << area << std::endl;

    return 0;
}


#endif

#if 0

#include <iostream>

template <typename T>
constexpr void printInfo(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integer Value: " << value << std::endl;
    } else {
        std::cout << "Non-Integer value: " << value << std::endl;
    }
}

int main() {
    printInfo(10);
    printInfo(3.15);
    return 0;
}


#endif

#if 0

#include <cstddef>
#include <iostream>
#include <stdexcept>
 
class conststr // conststr is a literal type
{
    const char* p;
    std::size_t sz;
public:
    template<std::size_t N>
    constexpr conststr(const char(&a)[N]) : p(a), sz(N - 1) {}
 
    constexpr char operator[](std::size_t n) const
    {
        return n < sz ? p[n] : throw std::out_of_range("");
    }
 
    constexpr std::size_t size() const { return sz; }
};
 
constexpr std::size_t count_lower(conststr s)
{
    std::size_t c{};
    for (std::size_t n{}; n != s.size(); ++n)
        if ('a' <= s[n] && s[n] <= 'z')
            ++c;
    return c;
}
 
// An output function that requires a compile-time constant N, for testing
template<int N>
struct constN
{
    constN() { std::cout << N << '\n'; }
};
 
int main()
{
    std::cout << "the number of lowercase letters in \"Hello, world!\" is ";
    constN<count_lower("Hello, world!")>(); // the string literal is implicitly
                                            // converted to conststr
}

#endif