#pragma once

#include <string>

class Visitor;

class Entity {
    public:
        virtual std::string describe() const= 0;
        virtual void accept(Visitor&)= 0;
        virtual ~Entity() = default;
};