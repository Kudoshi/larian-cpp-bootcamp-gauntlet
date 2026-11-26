#include "SaveGameFacade.hpp"

int main()
{
    // main.cpp: knows only the facade
    SaveGameFacade save;
    save.save(GameState{3, 27}, "save.dat");   // one call, correct order guaranteed

    return 0;
}