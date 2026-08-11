#pragma once
#include "Entity.hpp"

class Player : public Entity {
    public:
        explicit Player(std::string name, int maxHp, int armor) : Entity(std::move(name), maxHp), m_armor(armor) {}  
        ~Player() override = default;
        std::string describe() const override;
        void takeDamage(int amount) override;   // default: full damage

    private:
        int m_armor;
};
