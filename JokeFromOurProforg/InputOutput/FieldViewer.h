#ifndef SURVIVAL_FIELDVIEWER_H
#define SURVIVAL_FIELDVIEWER_H

#include "Field/Field.h"
#include "InputOutput/CellView.h"

#include <iostream>

class FieldViewer {
public:
    void View(Field const& field);

private:

    enum FieldObj {
        BORDER_ABOVE_AND_BOTTOM,
        BORDER_LEFT_AND_RIGHT,
        BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM,
        BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE,
        PLAYER
    };

    char HandleObject(FieldObj type);

    CellViewer mCellViewer;
};

#endif //SURVIVAL_FIELDVIEWER_H