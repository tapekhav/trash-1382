#include "CellFactory.h"

Cell* CellFactory::getCell(std::string cellType) {
    return cellsType.at(cellType);
}
