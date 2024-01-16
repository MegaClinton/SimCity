#include "Pollution.h"

Pollution::Pollution(int width, int height) : width(width), height(height) {
    // Initialize the pollution grid with all cells having zero pollution
    initialize();
}

void Pollution::initialize() {
    pollutionGrid.resize(height, std::vector<int>(width, 0));
}

void Pollution::simulate(int timeStep, const std::vector<std::vector<char>>& cityLayout, const std::vector<std::vector<int>>& populationGrid) {
    std::vector<std::vector<int>> newPollutionGrid = pollutionGrid; // Create a new grid to store updated pollution levels

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int currentPollution = pollutionGrid[y][x];

            // Determine the cell type based on the city layout
            char cellType = cityLayout[y][x];

            
            if (cellType == 'I') {
                // Industrial cell, pollution production
                int pollutionProduction = populationGrid[y][x]; // Pollution produced based on population
                currentPollution += pollutionProduction;
            } else {
                // Residential and commercial cells, pollution spread
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int neighborX = x + dx;
                        int neighborY = y + dy;

                        if (neighborX >= 0 && neighborX < width && neighborY >= 0 && neighborY < height) {
                            int neighborPopulation = populationGrid[neighborY][neighborX];
                            int pollutionSpread = neighborPopulation / (1 + dx * dx + dy * dy); // Adjust spread based on distance
                            currentPollution += pollutionSpread;
                        }
                    }
                }
            }

            // Update the new grid with the calculated pollution level for this cell
            newPollutionGrid[y][x] = currentPollution;
        }
    }

    // Replace the old pollution grid with the updated grid
    pollutionGrid = newPollutionGrid;
}

int Pollution::getPollutionLevel(int x, int y) const {
    // Bounds checking to ensure (x, y) is within the grid
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return pollutionGrid[y][x];
    }
    return 0; // Return 0 if out of bounds
}

