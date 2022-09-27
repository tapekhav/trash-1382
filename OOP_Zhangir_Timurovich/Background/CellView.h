#pragma once

#include "Cell.h"

class CellView {
public:
    explicit CellView(Cell c);
    char get_view();
private:
    char view;
};

