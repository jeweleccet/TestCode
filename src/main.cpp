#include <iostream>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

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