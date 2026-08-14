#include <string>
#include <iostream>
#include "Grid.hpp"

void PrintStartGoalCell(const Grid& grid)
{
    std::cout << "start S = (" << grid.start().x << "," << grid.start().y << ")\n";
    std::cout << "goal G = (" << grid.goal().x << "," << grid.goal().y << ")\n";
}

void GetNeighbour(const Grid& grid, int x, int y)
{
    // neighbours(4,4): (3,4) (4,3)

    std::cout << "neighbours(" << x << "," << y << "): ";
    
    std::vector<Cell> neighbours = grid.neighbours(Cell{x, y});

    for (const auto& neighbour : neighbours)
    {
        std::cout << "(" << neighbour.x << "," << neighbour.y << ") ";
    }

    std::cout << "\n";
}

int main(int argc, char* argv[])
{
    std::string path = argv[1];

    // Cell startCell;
    // Cell goalCell;
    Grid grid = Grid::load(path);

    PrintStartGoalCell(grid);

    for (int i = 2; i < argc-1; i++)
    {
        int xIdx = i;
        int yIdx = i + 1;
        
        if (i + 1 >= argc) break;

        GetNeighbour(grid, std::stoi(argv[xIdx]), std::stoi(argv[yIdx]));

        i++; // Double increment
    }
    
    return 0;
}




/**
 * Output example:
$ ./grid maps/simple.txt 0 0 2 2 4 4
S....
.###.
...#.
.#.G.
.....
start S = (0,0)
goal  G = (3,3)
neighbours(0,0): (1,0) (0,1)
neighbours(2,2): (1,2) (2,3)
neighbours(4,4): (3,4) (4,3)
 */