#include "Ducks.h"

Ducks::Ducks(int width, int height) : width (width), height (height) {
    //initializes empty Duck grid
    initialize();
}


void Ducks::initialize() {
    duckPopGrid.resize(height, vector<int>(width,0));
    duckWatchGrid.resize(height, vector<float>(width,0));
} //sets overall size of duck grids

void Ducks::duckMultiMath(const vector<vector<char>>& cityLayout, const vector<vector<int>>& populationGrid, vector<vector<int>>& pollutionGrid) {
    vector<vector<int>> newDuckPop = duckPopGrid;
    vector<vector<float>> newDuckWatch = duckWatchGrid;
    //Creates grids for both duck population and duck watching possibility

    float areaMulti;
    int pollute;
    int duckBase = 4*(width*height);

    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            pollute = pollutionGrid[h][w];
            if (cityLayout[h][w] == 'P') {
                areaMulti = .05;
            }
            if (cityLayout[h][w] == 'I') {
                areaMulti = .2;
            }
            if (cityLayout[h][w] == '-') {
                areaMulti = .3;
            }
            if (cityLayout[h][w] == 'R') {
                areaMulti = .4;
            }
            if (cityLayout[h][w] == 'C' ) {
                areaMulti = .5;
            }
            if (cityLayout[h][w] == 'T') {
                areaMulti = .7;
            }
            if (cityLayout[h][w] == '#') {
                areaMulti = .9;
            }
            else {
                areaMulti = 1.0;
            }
        float regionMulti = (areaMulti/pollute);
        newDuckPop[h][w] = regionMulti*duckBase;
        //Sets the number of ducks for that cell based on regional multiplier and the base number of ducks
        newDuckWatch[h][w] = newDuckPop[h][w]/populationGrid[h][w];
        //Sets likelihood of ducks watching based upon the number of ducks vs the number of people
        }
    }   
        duckPopGrid =  newDuckPop;
        duckWatchGrid = newDuckWatch;
}

int Ducks::getCellDuckTotal (int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return duckPopGrid[y][x];
    } 
    else {return 0;}
}  //returns total ducks in a cell

float Ducks::getCellDuckWatchers (int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return duckWatchGrid[y][x];
    } 
    else {return 0;}
}//returns likelihood of being watched by a duck in a cell


