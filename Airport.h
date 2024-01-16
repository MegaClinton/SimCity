#ifndef SIM_CITY_AIRPORT_H
#define SIM_CITY_AIRPORT_H

#include "Cell.h"
#include <vector>

class Airport {
public:
    Airport();

    static void updateCell(Cell& cell, const std::vector<std::vector<Cell>>& cells, const std::vector<Cell>& adjacentCells, int& totalSecurityBreaches, int& totalPassengers);

private:
    static const int WAITING_TIME_THRESHOLD = 3; // Threshold for waiting time
};

#endif //SIM_CITY_AIRPORT_H

