#pragma once
#include "Entity.hpp"

class Player : public Entity {
    public:
        explicit Player(std::string name) : Entity(std::move(name)) {}  
        std::string describe() const override;      // -> "Player <name>"
        ~Player() override = default;
};
