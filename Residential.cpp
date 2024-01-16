#include "Residential.h"

void Residential::updateCell(Cell& cell,const vector<vector<Cell>>& cells,vector<Cell> adjacentCells, int& workers)
{
    int adjacentTo = 0; //initialize number of cells that have a greater population

    for(auto & it : adjacentCells) //search adjacent cells of given cell
    {
        //if adjacent cell is powerline, increase population by 1 and stop looking for powerlines
        if((cell.getPopulation() == 0) && it.getType() == "T")
        {
            workers++;
            cell.setPopulation(cell.getPopulation() + 1);
            break;
        }

    }
    for(auto & it : adjacentCells)
    {
        //if adjacent cell has population >=1 and cell has population of 0, increase population
        if ((cell.getPopulation() == 0) && (it.getPopulation() >= 1))
        {
            workers++;
            cell.setPopulation(cell.getPopulation() + 1);
            break;
        }
        //update how many adjacent cells haves a greater population than given cell
        else if (it.getPopulation() >= cell.getPopulation())
        {
            adjacentTo++;
        }
    }

    //if number of adjacent cells is at least 2 times greater than the cell population and cell population >=1, increase population
    if(adjacentTo >= (2 * cell.getPopulation()) && cell.getPopulation() >=1)
    {
        workers++;
        cell.setPopulation(cell.getPopulation() + 1);
    }
}

//default constructor
Residential::Residential()
= default;



