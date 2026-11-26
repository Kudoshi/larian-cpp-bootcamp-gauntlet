#include "Writer.hpp"
#include <fstream>
#include <iostream>

void Writer::write(const std::string& path, std::string& packed, unsigned sum) const
{
    (void)sum;
    
    std::ofstream file(path);
    
    file << packed;

    std::cout << "write  -> " << path << " (" << (file.tellp()) << " bytes)\n";

    file.close();

}