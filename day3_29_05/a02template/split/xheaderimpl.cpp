#include "xheader.h"

template <typename T>
ElectronicComponent<T>::ElectronicComponent(const std::string& name, T value)
    : name(name), value(value) {}

template <typename T>
void ElectronicComponent<T>::print() const {
    std::cout << "Component: " << name << ", Value: " << value << std::endl;
}

template class ElectronicComponent<int>;
template class ElectronicComponent<double>;
template class ElectronicComponent<std::string>;

