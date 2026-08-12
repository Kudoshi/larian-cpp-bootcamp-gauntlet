#include <iostream>
#include <map>
#include <vector>
#include "Entity.hpp"

int main()
{
    std::map<int, Entity> entities;
    entities[7] = Entity{7, "orc", 30};
    entities[2] = Entity{2, "bat", 8};
    entities[42] = Entity{42, "boss", 300};
    entities[13] = Entity{13, "rat", 4};

    std::vector<int> findIds = {42, 99};

    for (const auto& id : findIds)
    {
        auto entityFind = entities.find(id);

        std::cout << "id " << id << ": ";

        if (entityFind != entities.end())
        {
            std::cout << entityFind->second.name << "\n";
        }
        else
        {
            std::cout << "(not found)\n";
        }
    }

    std::cout << "-- entities by id --\n";

    for (const auto& entity: entities)
    {
        std::cout << entity.first << " " << entity.second.name << "\n";
    }
    
   


}