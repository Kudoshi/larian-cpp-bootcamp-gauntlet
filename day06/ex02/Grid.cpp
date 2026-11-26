#include "Grid.hpp"
#include <fstream>
#include <iostream>

Grid Grid::load(const std::string& path)
{
    std::ifstream file(path);

    if (!file)
    {
        std::cerr << "File not found: " << path << "\n";
        throw std::runtime_error("File not found: " + path);
    }    

    std::string mapASCII;
    char c;
    int row = 0;
    int col = 0;

    Grid grid;
    std::vector<Cell> cells;
    while (file.get(c))
    {
        std::cout << c;

        if (c == 'S')
        {
            grid.m_startCell.x = col;
            grid.m_startCell.y = row;
        }
        else if (c == 'G')
        {
            grid.m_goalCell.x = col;
            grid.m_goalCell.y = row;
        }

        

        // Update next:
        if (c == '\n')
        {
            if (grid.m_maxCol == 0) grid.m_maxCol = col;
            row++;
            grid.m_maxRow = row;

            grid.m_cells.emplace_back(cells);
            cells.clear();
            col = 0;
        }
        else
        {
            mapASCII += c;
            cells.emplace_back(Cell{col, row});

            col++;
        }
    }

    std::cout << "\n";

    grid.m_mapAscii = mapASCII;

    return grid;
}

bool Grid::inBounds(Cell c) const
{
    return 
        c.y >= 0 && 
        c.y < m_maxRow &&
        c.x >= 0 &&
        c.x < m_maxCol;
}

bool Grid::isOpen(Cell c) const
{
    int totalIndex = c.y * m_maxCol + c.x;
    
    if (m_mapAscii[totalIndex] == '#')
        return false;

    return true;
}

std::vector<Cell> Grid::neighbours(Cell c) const
{
    std::vector<Cell> out;
    const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};   // pair i = one step: (+1,0) right,
    for (int i = 0; i < 4; ++i) {                           // (-1,0) left, (0,+1) down, (0,-1) up
        Cell n{c.x + dx[i], c.y + dy[i]};
        if (inBounds(n) && isOpen(n)) out.push_back(n); // silently drop off-map cells and walls
    }
    return out;


}

Cell Grid::start() const
{
    return m_startCell;
}

Cell Grid::goal() const
{
    return m_goalCell;
}

Cell Grid::getCell(int x, int y) const
{
    return m_cells[y][x];
}