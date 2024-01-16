#include "Industrial.h"
#include "Cell.h"

using namespace std;

/*
    Create Cell object with type I, which can produce goods according to population, and will produce pollution
    equivalent to population
*/
Industrial::Industrial()
=default;

/*
    (Will be called each timestep)
    1. Check population, population of adjacent cells and available power, and update cell if following conditions met:
        I. If cell pop == 0, 
            a. has adjacent powerline in current timestep, and at least 2 available workers, increase population by 1 next 
                timestep
            b. Is adjacent to at least one cell with population of at least 1, And at least 2 available workers, increase 
                population by 1 next timestep
        II. If cell pop == 1
            a. is adjacent to at least two cells with a population of at least 1, and there are at least 2 available workers, 
                increase population by 1 next timestep
        III. If cell pop == 2
            a. is adjacent to at least four cells with a population of at least 2, and there are at least 2 available workers, 
                increase population by 1
        
*/
void Industrial::UpdateCell(Cell& cell, vector <vector<Cell> >& cells, vector<Cell> adjacentCells, int& availableWorkers)
{
    int numAdjacent = 0;    //Stores number of relevant adjacent cells

    //1.
    if (availableWorkers >= 2)
    {
            //I
        if(cell.getPopulation() == 0)   
        {
            for(auto it : adjacentCells)       //Check adjacent cells for power (type T == power line)
            {
                if(it.getType() == "T" || it.getType() == "#")
                {
                    cell.setPopulation(cell.getPopulation() + 1);
                    growth = 1;
                    availableWorkers--;
                    break;
                }
                else if(it.getPopulation() >= 1)
                {
                    numAdjacent++;
                }
            }
            if (numAdjacent >= 1)
            {
                cell.setPopulation(cell.getPopulation() + 1);
                growth = 1;
                availableWorkers--;
            }
        }
            //II
        else if(cell.getPopulation() == 1)
        {
            for(auto it : adjacentCells)   //adjacent to at least two cells with a population of at least 1
            {
                if(it.getPopulation() >= 1)
                {
                    ++numAdjacent;
                }
            }
            if(numAdjacent >= 2)
            {
                cell.setPopulation(cell.getPopulation() + 1);
                growth = 1;
                availableWorkers--;
            }
        }

            //III
        else if(cell.getPopulation() == 2)
        {
            for(auto it : adjacentCells) //adjacent to at least four cells with a population of at least 2
            {
                if(it.getPopulation() >= 2)
                {
                    ++numAdjacent;
                }
            }
            if(numAdjacent >= 4)
            {
                cell.setPopulation(cell.getPopulation() + 1);
                growth = 1;
                availableWorkers--;
            }
        }
        else
        {
            growth = 0;
        }
    }
    else
    {
        growth = 0;
    }
}

bool Industrial::getGrowth()
{
    return growth;
}

