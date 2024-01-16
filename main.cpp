#include "main.h"

/*
    Read input files to store the initial region layout and configuration settings
        Cell objects
    Output map/region state every time step
    Output final region state
*/

void displayCells(const vector<vector<Cell>>(&cells), int workers, int goods, float students) //Function displays current region state
{
    for(auto & i : cells)
    {
        for(Cell j : i)
        {
            j.display();
            cout << "  ";
        }
        cout << endl;
    }
    cout << endl << "Available Workers: " << workers << endl;
    cout << "Available Goods: " << goods << endl;
    cout << "Total students: " << students << endl;
}

bool isValidPos(int i, int j, int n, int m) //checks if position of element in array is valid
{
    if(i < 0 || j < 0 || i > n - 1 || j > m - 1)
    {
        return false;
    }
    return true;
}

vector<Cell> getAdjacent(vector<vector<Cell>> cells, int i, int j) //gets adjacent elements of chosen cell
{
    int n = cells.size(); //size of 2d array
    int m = cells[i].size(); //size of row of cell

    vector<Cell> v; //where adjacent elements will be stored

    if (isValidPos(i - 1, j - 1, n, m))
        v.push_back(cells[i - 1][j - 1]);
    if (isValidPos(i - 1, j, n, m))
        v.push_back(cells[i - 1][j]);
    if (isValidPos(i - 1, j + 1, n, m))
        v.push_back(cells[i - 1][j + 1]);
    if (isValidPos(i, j - 1, n, m))
        v.push_back(cells[i][j - 1]);
    if (isValidPos(i, j + 1, n, m))
        v.push_back(cells[i][j + 1]);
    if (isValidPos(i + 1, j - 1, n, m))
        v.push_back(cells[i + 1][j - 1]);
    if (isValidPos(i + 1, j, n, m))
        v.push_back(cells[i + 1][j]);
    if (isValidPos(i + 1, j + 1, n, m))
        v.push_back(cells[i + 1][j + 1]);

    return v;
}

void updateResidentialCells(vector<vector<Cell>>& cells, int& workers)
{
    vector<vector<Cell>> newCells = cells;  // Create a copy of the current state

    for (int i = 0; i < cells.size(); i++) {
        for (int j = 0; j < cells[i].size(); j++) {
            if (cells[i][j].getType() == "R")
            {
                // Store adjacent cells from the previous time step
                vector<Cell> adj = getAdjacent(cells, i, j);
                // Update residential cell in the current time step
                Residential::updateCell(newCells[i][j], newCells, adj,workers);
                //if the person in that cell does not have a job, add to available workers and update job status of person
            }
        }
    }

    // After processing all cells, update the original cells with the new state from the copy
    cells = newCells;
}

void updateSchoolCells(vector<vector<Cell>>& cells, float& students)
{
    vector<vector<Cell>> newCells = cells;  // Create a copy of the current state

    for (int i = 0; i < cells.size(); i++) {
        for (int j = 0; j < cells[i].size(); j++) {
            //traverse roads
            if (cells[i][j].getType() == "-")
            {
                // Store adjacent cells from the previous time step
                vector<Cell> adj = getAdjacent(cells, i, j);
                //Update road cell if conditions met
                School::updateCell(newCells[i][j], newCells, adj,students);
            }
        }
    }
    // After processing all cells, update the original cells with the new state from the copy
    cells = newCells;
}

void updateIndustrialCells(vector<vector<Cell>>& cells, int &availableWorkers, int &availableGoods){
    vector<vector<Cell>> newCells = cells;  // Create a copy of the current state
    //int goods;
    for (int i=0; i < cells.size(); i++){
        for(int j=0;j<cells[i].size();j++){
            Industrial ind;
            if(cells[i][j].getType() == "I"){
                vector<Cell> adj = getAdjacent(cells, i, j);    // Store adjacent cells from the previous time step
                ind.UpdateCell(newCells[i][j], newCells, adj, availableWorkers);    // Update Industrial cells in the next time step
                if(ind.getGrowth() == 1)
                {  
                    availableGoods += newCells[i][j].getPopulation();    //Add population to goods          
                }
            }
        }
    }
    cells = newCells;
}

void updateCommercialCells(vector<vector<Cell>>& cells, int &availableWorkers, int &availableGoods){
    vector<vector<Cell>> newCells = cells;  // Create a copy of the current state
    for (int i=0; i < cells.size(); i++){
        for(int j=0;j<cells[i].size();j++){
            Commercial c;
            if(cells[i][j].getType() == "C"){
                vector<Cell> adj = getAdjacent(cells, i, j);    // Store adjacent cells from the previous time step
                c.can_grow(newCells[i][j], newCells, adj, availableWorkers, availableGoods);    // Update commercial cells in the next time step                
            }
        }
    }
    cells = newCells;
}

int main()
{
    //Read in configuration File:
    ifstream fin;
    string configFile;
    cout << "Input the configuration file name: ";
    cin >> configFile;
    fin.open(configFile);
    if (fin.fail()) {       //Check for error opening file, exit (1) represents fin fail error
        cout << "File error." << endl;
        exit(1);
    }

    string regionLayoutFile;
    int maxSteps;
    int refreshRate;
    string drop;

    //Store Refresh Rate and Simulation Length (max steps) from configuration file
    getline(fin, drop, ':');
    getline(fin, regionLayoutFile);
    getline(fin, drop, ':');
    fin >> maxSteps;
    getline(fin, drop, ':');
    fin >> refreshRate;
    fin.close();


    //Read in Region Layout file
    fin.open(regionLayoutFile);
    if (fin.fail()) {       //Check for error opening file, exit (1) represents fin fail error
        cout << "File error." << endl;
        exit(1);
    }

    //Display the configuration settings
    cout << endl << "Simulation Settings" << endl;
    cout << "Refresh Rate: every " << refreshRate << " steps" << endl;
    cout << "Max Steps: " << maxSteps << " steps" << endl << endl;

    string line;
    string type;

    vector<vector<Cell>> cells;

    //Store file information in vector of Cell objects
    while (getline(fin, line)) {
        vector<Cell> v;
        stringstream s(line);
        while (getline(s, type, ','))
        {
            Cell c;
            c.setType(type);
            v.push_back(c);
        }
        cells.push_back(v);
    }
    fin.close();

    int availableWorkers = 0; //workers of the residential population
    int availableGoods = 0;  // goods for commercial cells population
    float totalStudents = 0; //students enrolled in school

    cout << "Initial State" << endl;
    displayCells(cells,availableWorkers,availableGoods,totalStudents);
    //Output region state using displayCells function
    for(int i = 0; i < maxSteps; i+= refreshRate)
    {
        for(int j = 0; j < refreshRate; j++)
        {
            //Update residential cells
            updateResidentialCells(cells, availableWorkers);
            //Update industrial cells
            updateIndustrialCells(cells, availableWorkers, availableGoods);
            //Update commercial cells
            updateCommercialCells(cells, availableWorkers, availableGoods);
            //Update students
            updateSchoolCells(cells,totalStudents);
            //convert students into workers after certain time
            if(i > (0.5f * maxSteps))
            {
                availableWorkers += totalStudents;
                totalStudents = 0;
            }
        }
        //Display cells once the number of steps taken has matched the refresh rate
        cout << "State: " << i + refreshRate << endl;
        displayCells(cells,availableWorkers,availableGoods,totalStudents);
        cout << endl;
    }
}

