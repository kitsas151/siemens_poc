#if 1

#include <iostream>
#include <thread> // Include the <thread> header for std::thread

// Function to be executed by the first thread
void task1(std::string msg) {
    std::cout << "Task 1 says: " << msg << std::endl;
}

// Function to be executed by the second thread
void task2(int value) {
    std::cout << "Task 2 received value: " << value << std::endl;
}

int main() {
    // Create two threads
    std::thread t1(task1, "Hello from thread 1!");
    std::thread t2(task2, 42);

    // Do other work in the main thread...

    // Wait for both threads to finish
    t1.join();
    t2.join();

    return 0;
}


#endif

#if 1
//To prevent race conditions, you would typically use synchronization mechanisms like mutexes or locks to
// ensure that only one thread accesses the shared data at a time. For example, protecting the access
// to x with a mutex would avoid the race condition:

#include <iostream>
#include <thread>
#include <mutex>

int x = 0;
std::mutex mtx; // Mutex to protect access to x

void incrementX() {
    for (int i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        x = x + 1;
    }
}

void decrementX() {
    for (int i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        x = x - 1;
    }
}

int main() {
    std::thread t1(incrementX);
    std::thread t2(decrementX);

    t1.join();
    t2.join();

    std::cout << "Final value of x (with mutex): " << x << std::endl;

    return 0;
}


#endif