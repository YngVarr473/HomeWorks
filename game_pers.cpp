#include <cstddef>
#include <iostream>
#include <string>

enum class State {IDLE, ATTACKING, DEFENDING, DEAD};

template <class T>
class Inventory {
private:
    class Node {
    public:
        Node(T data, std::string name): data(data), name(name), next(nullptr) {};

    private:
        std::string name;
        T data;
        Node *next;
    };

    Node* head;
    int Size;
public:
    ~Inventory();
    Inventory(int Size = 0, Node* head = nullptr): Size(Size), head(head) {};
    void addItem(T data, std::string name);
};

template <class T>
Inventory<T>::~Inventory() {
    std::cout << "Item, was deleted <: \n";
}

template <class T>
void Inventory<T>::addItem(T data, std::string name) {
    if (head == nullptr) {
        head = new Node(data, name);
    } else {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new Node<T>(data,name);
    }
    Size++;
};

template <class T>
class Character {
private:
    friend bool compareHealth(const Character& s, const Character& s1);
    Inventory<T> inv;

    std::string name;
    int health;
    State state = State::IDLE;
public:
    Character(std::string name, int health)
        : name(name), health(health) {}

    std::string get_name() {
        return this->name;
    }
    Character& takeDamage(int &amount) {
        health = health - amount;
        if (health <= 0) {
            state = State::DEAD;
        }
        return *this;
    }

    Character& to_health(int amount) {
        health = health + amount;
        return *this;
    }

    void changeState() {
        state = static_cast<State>((static_cast<int>(state) + 1) % 4);
    }

    void printStatus() const {
        std::cout << "Name - " << name << std::endl;
        std::cout << "Health - " << health << std::endl;
        switch(state) {
            case State::IDLE:
                std::cout << "Current state - IDLE";
                break;
            case State::ATTACKING:
                std::cout << "Current state - ATTACKING";
                break;
            case State::DEFENDING:
                std::cout << "Current state - DEFENDING";
                break;
            case State::DEAD:
                std::cout << "Current state - DEAD";
                break;
        }
    }

    Character& attack(Character& target, int damage) {
        target.takeDamage(damage);
        if (target.state == State::DEAD) {
            std::cout << "Target is DEAD" << std::endl;
        }
        return *this;
    }
};

template <typename T>
bool compareHealth(const Character<T>& s, const Character<T>& s1) {
    return s.health > s1.health;
}

int main() {
    Character<int> Drag {"dragon", 320};
    Character<int> Human {"alite", 80};

    Human.attack(Drag, 320);

}
