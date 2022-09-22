#ifndef SURVIVAL_FIELDVIEWER_H
#define SURVIVAL_FIELDVIEWER_H

#include "Field/Field.h"

#include <iostream>

class FieldViewer {
public:
    void View(Field const& field);

private:
    enum CellView {
        EMPTY_CELL = ' ',
        PLAYER = 'P',
        WALL_CELL = 219,
        EVENT_CELL = '#'
    };

    enum FieldView {
        BORDER_ABOVE_AND_BOTTOM = '-',
        BORDER_LEFT_AND_RIGHT = '|',
        BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM = '\\',
        BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE = '/'
    };

    char HandleView(CellType type) const;
};

#endif //SURVIVAL_FIELDVIEWER_H