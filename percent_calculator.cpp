#include <iostream>
#include <cmath>

int main() {
    int p, x, y, k;
    std::cin >> p >> x >> y >> k;
    
    int total_cent;
    total_cent = (x * 100) + y;
    
    for (int i = 0; i < k; i++) {
        total_cent += (total_cent * p) / 100;
    }
    
    int k_rubles = total_cent / 100;
    int k_cent = total_cent % 100;
    
    std::cout << k_rubles << " " << k_cent;
    return 0;
}