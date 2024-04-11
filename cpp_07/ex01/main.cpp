#include "Iter.hpp"
#include <iostream>

template<typename T>
void printElement(T const & elem) {
    std::cout << elem << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, printElement<int>);

    std::string stringArray[] = {"Hello", "World", "Template", "Function"};
    iter(stringArray, 4, printElement<std::string>);
    
    return 0;
}