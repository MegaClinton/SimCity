/*
    Cell header, includes dependencies and function headers
*/

#ifndef MAIN_CPP_CELL_H
#define MAIN_CPP_CELL_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Cell
{
public:

    //Constructors

    //Default Constructor
    Cell();
    
    //Parameterized Constructor
    Cell(int population, string type, bool hasJob);

    //Functions
    void setPopulation(int population);
    int getPopulation();

    void setType(string type);
    string getType();

    void setHasJob(bool hasJob);
    bool isHasJob() const;

    const void display();

private:
    bool hasJob;
    int population;
    string type;
};


#endif //MAIN_CPP_CELL_H
