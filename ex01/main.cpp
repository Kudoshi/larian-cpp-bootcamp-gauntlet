// starter.cpp: leaks on the early-return path, and never frees on the normal one
#include <iostream>
#include "Owned.hpp"

int fight(bool flee){
    if (flee) 
    {
        return -1;     
    }
    else
    {
        Owned owned = Owned();
        return owned->hp;
    }
    
}
int main(){
    std::cout << fight(false) << ' ' << fight(true) << '\n';
}

// Command to run memory leak check:
// valgrind --leak-check=full ./a.out