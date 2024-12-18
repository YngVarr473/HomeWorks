#include <iostream>
#include <cmath>

int main() {
    double a = 2.7;
    double c = 6;

double result = ((((4 * std::pow(a, 2)) - (6 * a * c)) / ((2 * a) - (3 * c))) 
                - ((std::sqrt(6 * a * c) + (9 * std::pow(c, 2))) / std::pow((2 * a) + (3 * c), 2))) 
                * ((6 * a + 9) / (4 * a + 9));


std::cout << result;
    return 0;
}
