#include "Commercial.h"

Commercial::Commercial()
= default;

void Commercial::can_grow(Cell& cell,const vector<vector<Cell>>& cells,vector<Cell> adjacentCells, int& availableWorkers, int& availableGoods){
    int countOfGreaterThanOne = 0;  //initialize number of cells that have a greater population

    for(auto & it : adjacentCells){     //search adjacent cells of given cell
        if(it.getPopulation() >= 1){    //checking if adjacent cell's population is greater than 1
            countOfGreaterThanOne++;    // increament the counter
        }
    }
    for(auto & it : adjacentCells) //search adjacent cells of given cell
    {
        //if cell population is zero, adjacent cell is powerline or powerline on a road, and has worker and good, then increase population by 1
        if((cell.getPopulation() == 0) && (it.getType() == "T" || it.getType() == "#") && availableWorkers >= 1 && availableGoods >= 1)
        {
            cell.setPopulation(cell.getPopulation() + 1);
            availableWorkers--;
            availableGoods--;
            break;
        }
        // if cell population is zero, adjacent population is greater than 1, and has wroker and good, then increase population by 1.
        else if ((cell.getPopulation() == 0) && (it.getPopulation() >= 1) && availableWorkers >= 1 && availableGoods >= 1){
            cell.setPopulation(cell.getPopulation() + 1);
            availableWorkers--;
            availableGoods--;
            break;
        }
        // if cell population is 1, adjacent to more than 1 cell that has more than one population, and has worker and good, then increase population by 1.
        else if((cell.getPopulation() == 1) && countOfGreaterThanOne >= 2 && availableWorkers >= 1 && availableGoods >= 1){
            cell.setPopulation(cell.getPopulation() + 1);
            availableWorkers--;
            availableGoods--;
            break;
        }
    }
}
// accessors for workers and goods
int Commercial::getWorkers(){
    return workers;
}

int Commercial::getGoods(){
    return goods;
}

