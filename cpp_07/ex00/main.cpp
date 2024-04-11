#include "Header.hpp"
#include <iostream>

int main() {
    // Test swap with integers
    int x = 10, y = 20;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    // Test min and max with integers
    std::cout << "Min of x and y: " << min(x, y) << std::endl;
    std::cout << "Max of x and y: " << max(x, y) << std::endl;

    // Test swap, min, and max with doubles
    double a = 1.5, b = 2.5;
    std::cout << "\nBefore swap: a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "Min of a and b: " << min(a, b) << std::endl;
    std::cout << "Max of a and b: " << max(a, b) << std::endl;

    // Test min and max with std::string
    std::string first = "apple", second = "banana";
    std::cout << "\nMin of first and second: " << ::min(first, second) << std::endl;
    std::cout << "Max of first and second: " << ::max(first, second) << std::endl;

    return 0;
}
