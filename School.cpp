//
// Created by clinton on 11/7/2023.
//

#include "School.h"

void School::updateCell(Cell& cell,const vector<vector<Cell>>& cells,vector<Cell> adjacentCells,float& totalStudents)
{
    int adjacentTo = 0; //initialize number of residentials with population of 2
    float students = 0; //initialize number of students

    //traverse through the adjacent cells
    for(auto it: adjacentCells)
    {
        //if adjacent cell is residential and population is more than 2
        if(it.getType() == "R" && it.getPopulation() >= 2)
        {
            //increment adjacent variable
            adjacentTo++;
            //add to number of students
            students += ((.5f) * it.getPopulation());
        }
    }

    //if there were at least 3 adjacent residential cells
    if(adjacentTo >= 3)
    {
        //turn the road into a school
        cell.setType("S");
        //add to number of total students
        totalStudents += students;
    }

}


//default constructor
School::School()
= default;
