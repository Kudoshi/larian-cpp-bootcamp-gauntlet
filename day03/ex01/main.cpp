#include <iostream>
#include <vector>
#include <memory>
#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
    // main.cpp
    Entity* hero    = new Player("Aria");
    Entity* monster = new Enemy("Goblin", 12, {"dagger", "gold", "torch"});

    std::cout << hero->describe()    << '\n';
    std::cout << monster->describe() << '\n';

    std::cout << "--- cleaning up ---\n";
    delete hero;      
    delete monster;  
}