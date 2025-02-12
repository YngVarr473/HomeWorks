#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <wchar.h>

class Book {
public:
    int year_of_create;
    std::string title;
    std::string author;

    void show_info() {
        std::cout << year_of_create << "\t" << title << "\t" << author << std::endl;
    }

    Book(int year, std::string t_title, std::string a_author)
        : year_of_create(year), title(t_title), author(a_author) {}

    bool vs(const int year, const std::string& t_tiltle, std::string& a_author) const {
        return year_of_create == year && title == t_tiltle && author == a_author;
    }
};

class Library {

private:

    std::vector<Book> Lib {
        Book(2012,"C++ Primer", "Lippman"),
        Book(2008, "Clean Code", "Robert"),
        Book(1999, "The Pragmastic", "Dave")
    };

public:

    void add(const int year, const std::string title, const std::string author) {
        Book newbook(year, title, author);
        Lib.push_back(newbook);
    }

    void find(const int year, const std::string title, const std::string author) {

        auto it = std::find_if(Lib.begin(), Lib.end(), [year, title, author](const Book book) {
            return boook.vs(year, title, author);
        });

        if (it != Lib.end()) {
            std::cout << "Book found, position - " <<  it << std::endl;
        } else {
            std::cout << "The book was not found" << std::endl;
        }

    }

    void remove(const int year, const std::string title, const std::string author) {
        auto dizon = std::remove_if(Lib.begin(), Lib.end(), [year, title, author] (const Book& book) {
            return book.vs(year, title, author); 
        });

        Lib.erase(dizon, Lib.end());

    }

};

int main() {
    return 0;
}
