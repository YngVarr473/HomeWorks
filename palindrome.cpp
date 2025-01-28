#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

std::string readInput(const std::string& s1) {
    if (s1.length() == 0 || s1.length() == 1) {
        return "yes";
    }

    if(s1[0] == s1[s1.length() - 1]) {
        return readInput(s1.substr(1, s1.length() - 2));
    } else {
        return "no";
    }
}

int main() {
    std::string s1;
    std::cin >> s1;
    std::cout << readInput(s1) << std::endl;
    return 0;
}
