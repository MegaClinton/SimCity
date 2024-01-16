#include <iostream>
#include <vector>
#include "analysis.h"
using namespace std;

Analysis::Analysis() {
    x=0;
    y=0;
    analysisType='X';
}

Analysis::Analysis(int row, int col, char symbol)
{
    x=col;
    y=row;
    analysisType=symbol;

    change=false;
    powered=false;
}

char Analysis::getSymbol()
{
    return analysisType;
}

