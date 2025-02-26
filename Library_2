#include <iostream>
#include <fstream>
#include <string>

class Item {
    std::string title;
    std::string author;
    int year;
public:
    Item(std::string title, std::string author, int year)
        : title(title), author(author), year(year) {}

    virtual void show_info() const {
        std::cout << year << "\t" << title << "\t" << author << std::endl;
    }
};

class Book : public Item {
    std::string genre;
    int pageCount;
public:
    Book(std::string title, std::string author, int year, std::string genre, int pageCount)
        : Item(title, author, year), genre(genre), pageCount(pageCount) {}

    void show_info() const override {
        Item::show_info();
        std::cout << "Жанр: " << genre << "\tКоличество страниц: " << pageCount << std::endl;
    }
};

class Magazine : public Item {
    int issueNumber;
    int month;
public:
    Magazine(std::string title, std::string author, int year, int issueNumber, int month)
        : Item(title, author, year), issueNumber(issueNumber), month(month) {}

    void show_info() const override {
        Item::show_info();
        std::cout << "Номер выпуска: " << issueNumber << "\tМесяц: " << month << std::endl;
    }
};

class Reader {
    std::string name;
    std::string email;
    int phone;
    std::string path = "C:/Users/Asus/fuky.cpp/Library/reader.txt";
public:
    Reader(std::string name, std::string email, int phone)
        : name(name), email(email), phone(phone) {}

    void print() const {
        std::cout << name << "\t" << email << "\t" << phone << std::endl;
    }

    bool compare(const Reader& reader) const {
        return (name == reader.name && email == reader.email && phone == reader.phone);
    }

    bool check() const {
        std::ifstream fin(path);
        if (fin.is_open()) {
            std::string tempName, tempEmail;
            int tempPhone;
            while (fin >> tempName >> tempEmail >> tempPhone) {
                Reader temp(tempName, tempEmail, tempPhone);
                if (compare(temp)) {
                    return false;
                }
            }
        }
        return true;
    }

    void registerReader() const {
        if (check()) {
            std::ofstream fout(path, std::ios::app);
            if (fout.is_open()) {
                fout << name << "\t" << email << "\t" << phone << std::endl;
            }
            fout.close();
        }
    }
};

int main() {
    // Пример использования
    Reader reader("Иван Иванов", "ivan@example.com", 123456789);
    reader.registerReader();
    reader.print();

    Book book("Книга", "Автор", 2023, "Фантастика", 300);
    book.show_info();

    Magazine magazine("Журнал", "Редактор", 2023, 1, 5);
    magazine.show_info();

    return 0;
}
