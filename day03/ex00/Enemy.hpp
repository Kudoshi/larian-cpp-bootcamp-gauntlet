#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
    public:
        Enemy(std::string name, int hp) : Entity(std::move(name)), m_hp(hp) {} 
        ~Enemy() override = default;
        std::string describe() const override;
    private:
        int m_hp;
};