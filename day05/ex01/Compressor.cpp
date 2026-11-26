#include "Compressor.hpp"
#include <iostream>

std::string Compressor::compress(const std::string& text) const
{
    // input: level=3;hp=27

    std::string result;

    std::size_t equal = text.find("=");
    std::size_t semicolon = text.find(";");
    
    result += text.substr(equal + 1, semicolon - equal - 1);

    equal = text.find('=', semicolon);

    result += ';';
    result += text.substr(equal + 1);

    std::cout << "compress  -> " << result << " (" << text.size() << " -> " 
        << result.size() << " bytes)\n";

    return result;
}

// compress  -> 3;27 (13 -> 4 bytes)