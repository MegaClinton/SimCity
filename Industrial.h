#ifndef MAIN_CPP_INDUSTRIAL_H
#define MAIN_CPP_INDUSTRIAL_H

#include "Cell.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


class Industrial
{
    public:
        

        Industrial();           //Default constructor
        
      /*
        Checks population, and other factors, updates cell accordingly (described in depth in .cpp)

        Parameters are Cell pointer (cell being assigned Industrial), the vectors of Cell objects that form the map,
        another vector of cells that contains all adjacent Cells, and the number of available workers
      */
        void UpdateCell(Cell& cell, vector <vector<Cell> >& cells, vector<Cell> adjacentCells, int &availableWorkers); 

        bool getGrowth();
     private:

      bool growth;

};

#endif

