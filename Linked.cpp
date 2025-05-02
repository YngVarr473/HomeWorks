#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>

template <class T>
class List {
public:
    List();
    ~List();
    void push_back(T data);
private:
    class Node {
    private:
        T data;
        Node* next;
    public:
        Node(T data = T(), Node* next = nullptr) : data(data), next(next) {}
        friend class List; // <-- чтобы List имел доступ к private Node
    };

    int Size;
    Node* head;
};

template <class T>
List<T>::List() : Size(0), head(nullptr) {}

template <class T>
List<T>::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <class T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node(data);
        std::cout << "Allright \n";
    } else {
        Node* cur = head;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new Node(data);
        std::cout << "Allright \n";
    }
    Size++;
}
int main() {
    List<int> lst;
    lst.push_back(24);
    lst.push_back(42);
    lst.push_back(100);
}
