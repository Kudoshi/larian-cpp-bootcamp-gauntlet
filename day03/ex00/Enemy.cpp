#include "Enemy.hpp"

std::string Enemy::describe() const
{
    return  "Enemy " + m_name + " (hp " + std::to_string(m_hp) + ")";
}

// Enemy Goblin (hp 12)
