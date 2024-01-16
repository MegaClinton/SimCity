//
// Created by clinton on 11/7/2023.
//

#ifndef ANALYSIS_CPP_SCHOOL_H
#define ANALYSIS_CPP_SCHOOL_H
#include "Cell.h"


class School
        {
        public:
    School();
    static void updateCell(Cell& cell,const vector<vector<Cell>>& cells,vector<Cell> adjacentCells, float& totalStudents);

};

#endif //ANALYSIS_CPP_SCHOOL_H
