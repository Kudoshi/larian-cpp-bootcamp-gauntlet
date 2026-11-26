#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<int> spawns = {7, 2, 7, 42, 13, 2, 42};

    std::cout << "-- spawned (unique, sorted)\n";

    for (const auto& spawn : spawns)
    {
        std::cout << spawn << "\n";
    }

    std::cout << "count: " << std::to_string(spawns.size()) << "\n";

    std::cout << "is " << 42 << " spawned? " << (spawns.count(42) == 1? "yes" : "no") << "\n";
    std::cout << "is " << 99 << " spawned? " << (spawns.count(99) == 1? "yes" : "no") << "\n";

}