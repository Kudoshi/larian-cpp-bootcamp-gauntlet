#include "Owned.hpp"

Owned::Owned() : m_enemy(new Enemy()) { }

Owned::~Owned() {
    delete m_enemy;
}

Enemy* Owned::operator->(){
    return m_enemy;
}