#ifndef POLLUTION_H
#define POLLUTION_H

#include <vector>

class Pollution {
public:
    Pollution(int width, int height); // Constructor

    // Function to initialize the pollution grid
    void initialize();

    // Function to simulate pollution spread and its effects
    void simulate(int timeStep, const std::vector<std::vector<char>>& cityLayout, const std::vector<std::vector<int>>& populationGrid);

    // Function to get the pollution level at a specific cell
    int getPollutionLevel(int x, int y) const;

private:
    int width;  // Width of the city grid
    int height; // Height of the city grid

    // Data structure to store pollution levels in the city
    std::vector<std::vector<int>> pollutionGrid;
};

#endif

