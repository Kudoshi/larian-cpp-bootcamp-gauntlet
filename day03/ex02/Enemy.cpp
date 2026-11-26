#include "Enemy.hpp"

std::string Enemy::describe() const
{
    std::string describe = "Enemy " + m_name + " (hp " + std::to_string(currentHp()) + "/" + std::to_string(maxHp()) + ")";

    if (!isAlive())
    {
        describe += "[dead]";
    }
    return  describe;
    
}

// Enemy Goblin (hp 12)
