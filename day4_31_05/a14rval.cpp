
#if 0
#include <iostream>
#include <string>

class MyString {
private:
    std::string data;

public:

    MyString(std::string data) :data(data) {}

    MyString(const MyString& other)=default;

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data) {
        std::cout << "move constructor used";
        other.data = nullptr; // Transfer ownership
    }

    

    // Other constructors, destructor, etc.
};

// Usage:
MyString createString() {
    MyString temp("hello");
    return temp; // return type optimization.
}


int main()
{
        MyString obj = createString();

}

#endif


#if 0

#include <iostream>
#include <utility>

class DynamicArray {
private:
    size_t size_;
    int* data_;

public:
    DynamicArray(size_t size) : size_(size), data_(new int[size]) {
        for (size_t i = 0; i < size; ++i) {
            data_[i] = 0;
        }
    }

    // Move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data_;
    }

    void print() const {
        for (size_t i = 0; i < size_; ++i) {
            std::cout << data_[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray arr1(5);
    DynamicArray arr2(10);

    std::cout << "====== BEFORE MOVING ======" << std::endl;
    std::cout << "arr1: ";
    arr1.print();
    std::cout << "arr2: ";
    arr2.print();

    arr2 = std::move(arr1); // Using move assignment

    std::cout << "\n====== AFTER MOVING ======" << std::endl;
    std::cout << "arr1: ";
    arr1.print(); // arr1 is in a valid but unspecified state
    std::cout << "arr2: ";
    arr2.print();

    return 0;
}



#endif
