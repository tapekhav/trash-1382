#pragma once

#include "Cell.h"
#include "../CellTypes/CellType.h"

class CellView {
public:
    explicit CellView(Cell c);
    char get_view() const;
private:
    char view;
};

