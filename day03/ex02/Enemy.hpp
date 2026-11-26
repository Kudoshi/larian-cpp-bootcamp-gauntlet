#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
    public:
        Enemy(std::string name, int maxHp) : Entity(std::move(name), maxHp) {} 
        ~Enemy() override = default;
        std::string describe() const override;
};