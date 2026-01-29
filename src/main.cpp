
#include <iostream>
#include "fibonacci.h"

int main() {
    int count;
    std::cout << "Enter the number of Fibonacci terms: ";
    std::cin >> count;

    std::cout << "Fibonacci Series: ";
    for (int i = 0; i < count; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}