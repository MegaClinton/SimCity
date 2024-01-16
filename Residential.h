#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Cell.h"

using namespace std;

class Residential
{
public:
    Residential();
    static void updateCell(Cell& cell,const vector<vector<Cell>>& cells,vector<Cell> adjacentCells,int& workers);
private:
};
#endif
