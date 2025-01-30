#include <iostream>
#include <map>
#include <string>

std::string key_by_value(const std::map<std::string, std::string>& voc, const std::string value) {
    for(const auto& pair : voc) {
        if(pair.second == value) {
            return pair.first;
        } else if (pair.first == value) {
            return pair.second;
        }
    }
    return "";
}

int main() {
    std::map<std::string, std::string> voc;

    int n;
    std::cin >> n;

    std::string word, translation;

    for (int i = 0; i < n; i++) {
        std::cin >> word;
        std::cin >> translation;
        voc[word] = translation;
    }

    std::string value;
    std::cin >> value;

    std::cout << key_by_value(voc, value);
    
    return 0;
}
