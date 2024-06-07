


#if 0

#include <iostream>
#include <thread>
#include <semaphore.h> // POSIX semaphore

const int N = 3; // Maximum allowed concurrent accesses

sem_t mySemaphore; // Declare the semaphore

void worker(int id) {
    // Wait for the semaphore (decrement)
    sem_wait(&mySemaphore);

    // Access the shared resource
    std::cout << "Thread " << id << " accessing the resource." << std::endl;

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Release the semaphore (increment)
    sem_post(&mySemaphore);
}

int main() {
    // Initialize the semaphore
    sem_init(&mySemaphore, 0, N);

    // Create multiple threads
    constexpr int numThreads = 5;
    std::thread threads[numThreads];
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(worker, i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    // Clean up the semaphore
    sem_destroy(&mySemaphore);

    return 0;
}


#endif

#if 1


#include <iostream>
#include <thread>
#include <semaphore> // Include the <semaphore> header

std::counting_semaphore<1> mySemaphore(5); // Create a counting semaphore with initial value 1

void worker(int id) {
    // Wait for the semaphore (acquire)
    mySemaphore.acquire();

    // Access the shared resource
    std::cout << "Thread " << id << " accessing the resource." << std::endl;

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Release the semaphore
    mySemaphore.release();
}

int main() {
    constexpr int numThreads = 5;
    std::thread threads[numThreads];
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(worker, i);
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}




#endif