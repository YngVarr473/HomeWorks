#include <iostream>     
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int r;
    std::cin >> r;
    if (r == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::set<int> s;
    int temp = r;
    
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    std::set<int> copy;

    while (!s.empty()) {
        auto it = s.lower_bound(temp);
        if (it == s.end()) break;
        
        int x = *it;
        if (x >= temp && (copy.empty() || x - 3 >= temp)) {
            copy.insert(x);
            temp = x;
        }
        s.erase(it);
    }

    std::cout << copy.size() << std::endl;
    return 0;
}
