#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Visitor.hpp"
#include "DescribeVisitor.hpp"
#include "TotalHpVisitor.hpp"

int main()
{
    std::vector<std::unique_ptr<Entity>> entities;

    entities.emplace_back(std::make_unique<Orc>());
    entities.emplace_back(std::make_unique<Bat>());
    entities.emplace_back(std::make_unique<Boss>());

    DescribeVisitor describe;
    TotalHpVisitor  totalHp;

    std::cout << "-- describe --\n";
    for (auto& e : entities) e->accept(describe);

    std::cout << "-- total hp --\n";
    for (auto& e : entities) e->accept(totalHp);

    std::cout << totalHp.total << '\n';
}