#include <iostream>
#include <cmath>

int fib(int n) {
    if (n == 1) {
        return 1;
    } else {
        fib(n / 2);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::cout << fib(n) << std::endl;
}
