#ifndef LAB2_CELLFACTORY_H
#define LAB2_CELLFACTORY_H


#include <map>
#include "Cell.h"
#include "CellGrass.h"
#include "CellWall.h"
#include "CellPlayer.h"

class CellFactory {
public:
    Cell* getCell(std::string);
private:
    std::map<std::string, Cell*> cellsType{
            {"Grass", new CellGrass()},
            {"Wall", new CellWall()},
            {"Player", new CellPlayer()}
    };
};


#endif
