#ifndef SURVIVAL_FIELDVIEWER_H
#define SURVIVAL_FIELDVIEWER_H

#include "Field/Field.h"
#include "InputOutput/CellView.h"
#include "Enums.h"

#include <iostream>

class FieldViewer {
public:
    void View(Field const& field);

private:

    char HandleObject(EnumClass::FieldObj type);
    CellViewer mCellViewer;
};

#endif //SURVIVAL_FIELDVIEWER_H