#include "Checksum.hpp"
#include <iostream>

unsigned Checksum::of(const std::string& packed) const
{
    unsigned int sum = 0;

    for (unsigned char c : packed)
    {
        sum += c;
    }

    std::cout << "checksum  -> 0x" << std::hex << sum << "\n";

    return sum;
}

// checksum  -> 0xD7