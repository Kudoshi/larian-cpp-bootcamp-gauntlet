#pragma once
#include <string>
#include <vector>

struct Cell { int x, y; };

class Grid {
    public:
        static Grid load(const std::string& path);
        bool inBounds(Cell c) const;
        bool isOpen(Cell c) const;                   // in bounds and not '#'
        std::vector<Cell> neighbours(Cell c) const;  // walkable 4-neighbours
        Cell start() const;   // the 'S'
        Cell goal()  const;   // the 'G'
    private:
        Cell getCell(int x, int y) const;

        Cell m_startCell;
        Cell m_goalCell;
        std::string m_mapAscii;
        std::vector<std::vector<Cell>> m_cells;
        int m_maxRow = 0;
        int m_maxCol = 0;
        

};