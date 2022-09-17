#ifndef LABS_CELL_H
#define LABS_CELL_H

#include <iostream>
#include "structs.h"
#include <algorithm>

class Cell {
public:
    explicit Cell();
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);
    OBJECT get_obj() const;
    void set_obj(OBJECT obj);

private:
    void swap(Cell &other);
    OBJECT obj;
};

#endif //LABS_CELL_H
