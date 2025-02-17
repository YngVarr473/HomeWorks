#include <iostream>
#include <string>

enum class State {IDLE, ATTACKING, DEFENDING, DEAD};

class Character {
private:
    friend bool compareHealth(const Character& s, const Character& s1);

    std::string name;
    int health;
    State state = State::IDLE;    
public:
    Character(std::string name, int health) 
        : name(name), health(health) {}

    Character& takeDamage(int &amount) {
        health = health - amount;
        if (health <= 0) {
            state = State::DEAD;
        }
        return *this;
    }

    Character& health(int amount) {
        health = health + amount;
        return *this;
    }

    void changeState() {
        state = static_cast<State>(static_cast<int>(state) + 1) % 4);
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
 
bool compareHealth(const Character& s, const Character& s1) {
    return s.health > s1.health;
}

int main() {

}
