#if 0

#include <iostream>
#include <atomic> // Include the <atomic> header for std::atomic

int main() {
    std::atomic<int> counter(0); // Create an atomic integer

    // Increment the counter atomically
    counter.fetch_add(1, std::memory_order_relaxed);

    // Read the counter value atomically
    int value = counter.load(std::memory_order_relaxed);

    std::cout << "Counter value: " << value << std::endl;



    return 0;
}



/*
The memory order (e.g., std::memory_order_relaxed) specifies
 how memory accesses are synchronized between threads.



*/

#endif