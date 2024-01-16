#ifndef DUCKS_H
#define DUCKS_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "Residential.h"
#include "Pollution.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Cell.h"

using namespace std;

class Ducks  {
    public:

Ducks(int w, int h); //Constructor
void initialize(); //initializes Duck grid

int date; //matches whatever day of year is input

vector<vector<int>> duckPopGrid; //Stores total ducks
vector<vector<float>> duckWatchGrid; //Stores likelihood of ducks watching

void duckMultiMath(const vector<vector<char>>& cityLayout, const vector<vector<int>>& populationGrid, vector<vector<int>>& pollutionGrid); //math function to calculate total ducks for city, ducks in a cell, and likelihood (or number) of ducks watching individual

int getCellDuckTotal (int w, int h); //function to get total ducks in a cell
float getCellDuckWatchers (int w, int h); ////function to get likelihood of duck watching individual in cell

    private:
int width; //City width
int height; //City height
};

#endif
