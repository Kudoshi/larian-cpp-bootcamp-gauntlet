#include "Inventory.hpp"
#include <iostream>

Inventory::Inventory(const std::string& owner, std::initializer_list<std::string> items)
{
    m_owner = owner;
    m_count = items.size();

    std::string* array = new std::string[m_count];

    std::size_t i = 0;
    for (const std:: string& item : items)
    {
        array[i] = item;
        i++;
    }

    m_items = array;

    std::cout << "+ Inventory \t";

    std::cout << "(";

    for (std::size_t i = 0; i < m_count; ++i)
    {
        std::cout << m_items[i];

        if (i + 1 < m_count)
            std::cout << ", ";
    }

    std::cout << ") \n";

}

Inventory::~Inventory()
{
    std::cout << "- Inventory \t";

    std::cout << "(";

    for (std::size_t i = 0; i < m_count; ++i)
    {
        std::cout << m_items[i];

        if (i + 1 < m_count)
            std::cout << ", ";
    }

    std::cout << ") \n";
    delete[] m_items;
}


