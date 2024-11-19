#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int num;
    std::vector<int> numbers;

    // Считываем все числа из ввода и добавляем в массив
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    if (!numbers.empty()) {  // Проверяем, что массив не пуст
        numbers.pop_back();   // Удаляем последний элемент

        double total_num = 0;

        // Считаем сумму элементов массива
        for (int i = 0; i < numbers.size(); i++) {
            total_num += numbers[i];
        }

        // Вычисляем среднее арифметическое
        double sred_ar = total_num / numbers.size();

        // Если сумма элементов равна нулю, выводим 0
        if (total_num == 0) {
            std::cout << "0.00000000000" << std::endl;
        } else {
            // Выводим среднее арифметическое с точностью до 11 знаков
            std::cout << std::fixed << std::setprecision(11) << sred_ar << std::endl;
        }

    }

    return 0;
}