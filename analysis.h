#include<iostream>
#include <vector>

using namespace std;
#ifndef ANALYSIS_H
#define ANALYSIS_H

class Analysis
{
    public:
    int population=0;
    int totalAdjacentPopulation=0;
    vector<Analysis*> adjacentAnalysisVector;
    int count_adjacentTo[5]={0,0,0,0,0};
    bool adjacentToPowerline=false;

    int x;
    int y;
    char nodeType;
    bool hasGrown=false;
    bool change;
    bool powered;
    char analysisType;
    int pollution;
    int goods=0;
    int workers=0;

    Analysis();
    Analysis(int row, int col, char symbol);
    char getSymbol();
    int getTotalAdjacentPopulation();
    void updateTotalAdjacentPopulation();
    void updateAdjacentTo();
    void printAdjacent();
    void printAnalysis();

    string finalState;
    string pollutionSpread;

    Analysis(const string& f, const string& p) : finalState(f), pollutionSpread(p) {}
    void printState() const;
    void printPollutionSpread() const;
};

#endif

