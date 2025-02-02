#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::pair<int, int>> s;
    
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int id, v;
        std::cin >> id >> v;
        s.push_back({id, v});
    }

    std::sort(s.begin(), s.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for (const auto& now : s) {
        std::cout << now.first << " " << now.second << std::endl;
    }
}
