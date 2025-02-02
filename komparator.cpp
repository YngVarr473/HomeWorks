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
***
 Во время проведения олимпиады каждый из участников получил свой идентификационный номер – натуральное число. Необходимо отсортировать список участников олимпиады по количеству набранных ими баллов.

Входные данные

На первой строке дано число N (1 ≤ N ≤ 1000) – количество участников. На каждой следующей строке даны идентификационный номер и набранное число баллов соответствующего участника. Все числа во входном файле не превышают 105.

Выходные данные

В выходной файл выведите исходный список в порядке убывания баллов. Если у некоторых участников одинаковые баллы, то их между собой нужно упорядочить в порядке возрастания идентификационного номера.

Sample Input 1:

3
101 80
305 90
200 14

Sample Output 1:

305 90
101 80
200 14
***
