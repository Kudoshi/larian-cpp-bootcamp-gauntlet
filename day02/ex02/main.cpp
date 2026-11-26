// starter.cpp: leaks on the early-return path, and never frees on the normal one
#include <iostream>
#include <memory>

struct Enemy { int hp = 100; };

int fight(bool flee){

    if (flee) 
    {
        return -1;     
    }
    else
    {
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();

        return enemy.get()->hp;
    }
    
}
int main(){
    std::cout << fight(false) << ' ' << fight(true) << '\n';
}

// Command to run memory leak check:
// valgrind --leak-check=full ./a.out