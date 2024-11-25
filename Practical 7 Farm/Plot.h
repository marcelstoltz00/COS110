#ifndef PLOT_H
#define PLOT_H

 class Plant;

class Plot{
private:
    int numRows;
    int numCols;
    int **soil;
    int numPlants;
    Plant **plants;

public:
    Plot(int numRows, int numCols);
    ~Plot();

    void waterAllPlants();
    void harvestAllPlants();
    void printPlot();
    int getNumRows() ;
    int getNumCols() ;
    int *getPosition(int row, int col);
    Plant *getPlant(int *idx);
    int addPlant(Plant *plant);
};

#endif
