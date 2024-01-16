#include "Cell.h"

/*

    Cell object stores a cell's type and population. Also includes Display function to output Cell. Region is made of a vector of Cells

*/

//Return and set population of a cell 
int Cell::getPopulation()
{
    return population;
}
void Cell::setPopulation(int population)
{
    this->population = population;
};

//Return and set types of cells (C, R, or I represent Commercial, Residential, or Industrial)
string Cell::getType()
{
    return type;
};
void Cell::setType(string type)
{
    this->type = type;
};

//Prints out Cell, if population == 0, prints Type (C, R, I, etc.), if population > 0, prints population #
const void Cell::display()
{
    if(population == 0)
    {
        cout << type;
    }
    else
    {
        cout << population;
    }
}

//Default Cell constructor
Cell::Cell()
{
    population = 0;
    type = " ";
    hasJob = false;
}
//Parameterized Cell constructor
Cell::Cell(int population, string type, bool hasJob)
{
    this-> population = population;
    this-> type = type;
    this-> hasJob = hasJob;
}

bool Cell::isHasJob() const {
    return hasJob;
}

void Cell::setHasJob(bool hasJob) {
    Cell::hasJob = hasJob;
}


