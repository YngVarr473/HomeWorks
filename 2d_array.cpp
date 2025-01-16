#include <iostream>
#include <vector>
#include <iomanip> 

int main() {
    int n, m, k = 1;
    std::cin >> n >> m;

    std::vector<std::vector<int>> first(n, std::vector<int>(m));

    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            std::cin >> first[i][j];    
        }
    }

    for (int i = 0; i < n; ++i){
        if (i % 2 == 0) {
            for(int j = 0; j < m; ++j) {
                first[i][j] = k;
                k++;
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                first[i][j] = k;
                k++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(4) << first[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
} 
