#include <iostream>
#include "EntityFactory.hpp"
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> kinds = {"orc", "bat", "boss", "bat"};
    for (const auto& kind : kinds) {
        auto e = EntityFactory::make(kind);
        std::cout << "spawned " << e->describe() << '\n';
    }
}