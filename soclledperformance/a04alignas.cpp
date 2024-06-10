#if 0

#include <cstdlib>
#include <iostream>

int main() {
    alignas(16) int a[4];
    alignas(1024) int b[4];
    printf("%p\n", a);
    printf("%p", b);
}

#endif

#if 1

#include <iostream>
 
// objects of type S can be allocated at any address
// because both S.a and S.b can be allocated at any address
struct S
{
    double d;
    char a; // size: 1, alignment: 1
    char b; // size: 1, alignment: 1
    
}; // size: 2, alignment: 1
 
// objects of type X must be allocated at 4-byte boundaries
// because X.n must be allocated at 4-byte boundaries
// because int's alignment requirement is (usually) 4
struct X
{
    int n;  // size: 4, alignment: 4
    char c; // size: 1, alignment: 1
    // three bytes of padding bits
}; // size: 8, alignment: 4 
 
int main()
{
    std::cout << "alignof(S) = " << alignof(S) << '\n'
              << "sizeof(S)  = " << sizeof(S) << '\n'
              << "alignof(X) = " << alignof(X) << '\n'
              << "sizeof(X)  = " << sizeof(X) << '\n';
}


#endif

#if 0

#include <iostream>

struct alignas(16) MyStruct 
//struct MyStruct 
{
    char c;
    int i;
    short s;
};

int main() {
    MyStruct a;
    std::cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes\n";
    std::cout << "Address of 'a': " << &a << "\n";
    std::cout << "Address of 'a.c': " << static_cast<void*>(&a.c) << "\n";
    std::cout << "Address of 'a.i': " << &a.i << "\n";
    std::cout << "Address of 'a.s': " << &a.s << "\n";
}


/*

Cache Line Size:
The cache line is the smallest unit of data loaded from memory into the CPU cache.
Modern processors typically have cache lines of 64 bytes (but this can vary).
When data is accessed, the entire cache line containing that data is loaded into the cache.
Why Alignment Matters:
When a variable or data structure is aligned to the cache line boundary, it improves cache utilization and minimizes cache misses.
Cache misses occur when the CPU needs to fetch data from main memory because it’s not in the cache.
Unaligned data can span multiple cache lines, leading to extra cache misses and wasted memory.

//On a 32-bit processor, the aligned version would look like this:

//| c | padding | i | s |

//If the struct were packed (e.g., from network transmission), it might be unaligned
//| c | i | s |







*/


#endif

#if 0
#include <iostream>

class alignas(32) Str1
//class Str1
{
    public:
   int a, b, c, d, e;
};

int main()
{
        std::cout << "size of " << sizeof(Str1);
        


}


#endif


#if 1

int main()
{

    return 0;-O2 or -o3
}




#endif

/*

-o2 or -o3
-Os.
-Ofast
-fno-exceptions.
-fno-rtti.

link statically.
 



*/


