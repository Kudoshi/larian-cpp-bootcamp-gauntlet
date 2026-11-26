#pragma once
#include "Entity.hpp"

class Player : public Entity {
    public:
        explicit Player(std::string name) : Entity(std::move(name)) {}  
        ~Player() override = default;
        std::string describe() const override;
};
