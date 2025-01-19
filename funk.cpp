#include <iostream>
#include <vector>
#include <iomanip> 

int min(int a,int b) {
    std::cin >> a >> b;
    int x = (a < b) ? a : b;
    return x;
}

int min4(int a, int b, int c, int d) {
    int m1, m2, result;
    std::cin >> a >> b >> c >> d;
    m1 = min(a, b);
    m2 = min(c, d);
    result = min(m1, m2);
    return result;
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << min4(a, b, c, d) << std::endl;
    return 0;
} 
