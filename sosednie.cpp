#include <iostream>
#include <vector>

int n;

int main() {
    
std::cin >> n;
std::vector <int>vr_void(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vr_void[i];
    }

    for (int i = 0; i < vr_void.size(); i++) {
            if (vr_void[i - 1] >= 0 && vr_void[i] >= 0) {
                std::cout << vr_void[i -1]  << " " << vr_void[i];
                break;
            if (vr_void[i - 1] <= 0 && vr_void[i] <= 0) {
                std::cout << vr_void[i -1]  << " " << vr_void[i];
                break;
            } 
        }
    }
    return 0;
}
