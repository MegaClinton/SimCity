#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Cell.h"

using namespace std;

class Commercial{
public:
    
    Commercial();       // Default constructor for commercial class
    void can_grow(Cell& cell,const vector<vector<Cell>>& cells, vector<Cell> adjacentCells, int& availableWorkers, int& availableGoods);    //function to increase the population of commercial.

    int getGoods();      //goods accessor
    int getWorkers();   //workers accessor
private:
    int workers;
    int goods;
};
#endif

