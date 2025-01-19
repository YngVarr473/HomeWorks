#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath>

//sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

bool IsPointInSquare(double x, double y) {
    std::cin >> x >> y;
    double dist = abs(x) <= 1 && abs(y <= 1);
    return dist;
}

int main() {
    double x, y;
    std::cin >> x >> y;
    if (IsPointInSquare(x,y)) {
        std::cout << "YES";
    } else {
        std::cout << "NO"
    }
}
