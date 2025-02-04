***
Однажды, разбирая старые книги на чердаке, школьник Вася нашёл англо-латинский словарь. Английский он к тому времени знал в совершенстве, и его мечтой было изучить латынь. Поэтому попавшийся словарь был как раз кстати.

К сожалению, для полноценного изучения языка недостаточно только одного словаря: кроме англо-латинского необходим латинско-английский. За неимением лучшего он решил сделать второй словарь из первого.

Как известно, словарь состоит из переводимых слов, к каждому из которых приводится несколько слов-переводов. Для каждого латинского слова, встречающегося где-либо в словаре, Вася предлагает найти все его переводы (то есть все английские слова, для которых наше латинское встречалось в его списке переводов), и считать их и только их переводами этого латинского слова.

Помогите Васе выполнить работу по созданию латинско-английского словаря из англо-латинского.
***

#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <stddef.h>

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
    std::map<std::string, std::vector<std::string>> voc;

    int n;
    std::cin >> n;

    std::string line;

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        size_t pos = line.find(" - ");
        std::string word = line.substr(0, pos);
        
        std::string transl = line.substr(pos + 3);

        std::vector<std::string> vect;
        std::string trans;
        std::stringstream ss(transl);
        while (ss >> trans) {
            if (ss != ',') {
                vect.push_back(trans);
                voc[word] = vect;
            }
        }
    }

    for (const auto& pair : voc) {
        std::cout << "Ключ: " << pair.first << ", Значения: ";
        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

}
