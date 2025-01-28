#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

int main() {

    std::vector<std::string> text;
    std::string line;

    while(std::getline(std::cin, line)) {
        text.push_back(line);
    }

    int count = 0;
    
    for (const auto &line : text) {
        for (char c : line) {
            if (c == ' ') {
                count += 1;
            }
        }
    }
    
    std::cout << count + 1 << std::endl;

    return 0;
}
