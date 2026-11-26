#include <string>
#include <iostream>
#include "Grid.hpp"
#include <queue>
#include <map>
#include <cmath>

struct Node { Cell cell; int f; };                        // f = g + h
struct ByF { bool operator()(const Node& a, const Node& b){ return a.f > b.f; } };

int calculateH(Cell a, Cell b)
{
    return std::abs(a.x - b.x) + 
        std::abs(a.y - b.y);
}

bool cellIsEqual(Cell a, Cell b)
{
    return a.x == b.x && a.y == b.y;
}

std::vector<Cell> reconstruct(const std::map<Cell, Cell>& cameFrom, Cell goal)
{
    std::vector<Cell> path;
    Cell current = goal;
    path.push_back(current);

    while (cameFrom.count(current))
    {
        current = cameFrom.at(current);
        path.insert(path.begin(), current);
    }

    return path;
}

int main(int argc, char* argv[])
{
    (void) argc;
    std::string path = argv[1];
    Grid grid = Grid::load(path);

    
    std::priority_queue<Node, std::vector<Node>, ByF> open;   // min-heap on f

    Cell start = grid.start();
    Cell goal = grid.goal();

    std::map<Cell, int> gScore;
    std::map<Cell, Cell> cameFrom;

    gScore[start] = 0;

    open.push({start, calculateH(start, goal)});

    Node currentNode;
    while (!open.empty()) {
        currentNode = open.top(); 
        open.pop();          

        if (cellIsEqual(currentNode.cell, goal)) break;
        
        for (Cell neighbour : grid.neighbours(currentNode.cell)) {
            int tentativeG = gScore[currentNode.cell] + 1;

            if (!gScore.count(neighbour) || tentativeG < gScore[neighbour])
            {
                gScore[neighbour] = tentativeG;
                cameFrom[neighbour] = currentNode.cell;

                int f = tentativeG + calculateH(neighbour, goal);

                open.push({neighbour, f});
            }
        }
    }

    std::vector<Cell> pathCell = reconstruct(cameFrom, goal);     // start .. goal
    
    if (pathCell.size() <= 1)
    {
        std::cout << "no path\n";
    }
    else
    {
        std::cout << "path length: " << pathCell.size() - 1 << '\n'; 
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