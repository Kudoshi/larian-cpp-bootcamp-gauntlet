#include "Player.hpp"

std::string Player::describe() const 
{
    std::string describe = "Player " + m_name + " (hp " + std::to_string(currentHp()) + "/" + std::to_string(maxHp()) + 
        ", armor "+ std::to_string(m_armor) + ")";

    if (!isAlive())
    {
        describe += "[dead]";
    }
    return describe;
}      

// Player.cpp: armor soaks part of the hit, min 1 damage gets through
void Player::takeDamage(int amount){
    int reduced = std::max(1, amount - m_armor);
    std::cout << m_name << "'s armor soaks " << (amount - reduced) << '\n';
    Entity::takeDamage(reduced);   // delegate: base applies the hit and logs it
}

