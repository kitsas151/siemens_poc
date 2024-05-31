#if 1

//Initializer lists provide a concise way to initialize objects, whether they are built-in types,
// arrays, or user-defined classes.

#include <iostream>
#include <cassert>

namespace another
{



class IntArray {
private:
    int m_length{};
    int* m_data{};

public:
    IntArray(int length) : m_length{length}, m_data{new int[static_cast<std::size_t>(length)]{}} {
        // Initialize the array with zeros
    }

    ~IntArray() {
        delete[] m_data; // Clean up memory
    }

    int& operator[](const int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const {
        return m_length;
    }
};

void check() {
    IntArray array(5); // Create an IntArray with 5 elements
    array[0] = 5;
    array[1] = 4;
    array[2] = 3;
    array[3] = 2;
    array[4] = 1;

    for (int count = 0; count < array.getLength(); ++count) {
        std::cout << array[count] << ' ';
    }
    

}
}

namespace poc2
{

#include <initializer_list>
#include <iostream>

class IntArray {
private:
    int m_length{};
    int* m_data{};

public:
    IntArray(std::initializer_list<int> values) : m_length{static_cast<int>(values.size())},
                                                 m_data{new int[static_cast<std::size_t>(m_length)]{}} {
        int i = 0;
        for (auto value : values) {
            m_data[i++] = value;
        }
    }

    ~IntArray() {
        delete[] m_data; // Clean up memory
    }

    int& operator[](const int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const {
        return m_length;
    }

    // ... other member functions ...

    // Destructor and other functions remain the same
};

int main() {
    IntArray array{5, 4, 3, 2, 1}; // Using initializer list
    for (int count = 0; count < array.getLength(); ++count) {
        std::cout << array[count] << ' ';
    }

    return 0;
}


}//end of poc2


int main()
{
    int array[] {5, 4, 3, 2, 1}; // Using initializer list
    auto* dynamicArray = new int[5]{5, 4, 3, 2, 1}; // Using initializer list
// Remember to delete[] dynamicArray when done!
delete[] dynamicArray;


}

#endif