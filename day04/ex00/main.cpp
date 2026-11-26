#include <iostream>
#include <vector>
#include "Entity.hpp"


int main()
{
    std::vector<Entity> entities;
    entities.push_back(Entity{7, "orc", 30});
    entities.push_back(Entity{2, "bat", 8});
    entities.push_back(Entity{42, "boss", 300});
    entities.push_back(Entity({13, "rat", 4}));

    std::cout << "-- roster --\n";

    for (const auto& entity : entities)
    {
        std::cout << entity.id << " " << entity.name << " (hp " << entity.hp << ")\n";
    }

    std::cout << "-- survivors --\n";

    for(auto entity = entities.begin(); entity != entities.end();)
    {
        if (entity->hp <= 5)
        {
            entity = entities.erase(entity);
            continue;
        }
        
        std::cout << entity->id << " " << entity->name << " (hp " << entity->hp << ")\n";
        entity++;
    }
}