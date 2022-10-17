#ifndef CELL_H
#define CELL_H

#include "../Event/Event.h"
#include <iostream>
#include "../Support/Enum.h"
#include "CellType.h"


class Cell{
private:
    CellType *CurCellType;
    bool Passable;
    char CurIcon;
    Event *CurCellEvent;

public:
    Cell(CellType* StartCellType = new CellTypeLand(), bool StartPassable = true, char StartIcon = '.', Event *StartCellEvent = nullptr);

    Cell(const Cell &obj);

    Cell &operator=(Cell const &other);

    CellType* ShowCellType();
    char ShowCurIcon();
    bool ShowPassable();
    bool ActivationCheck();

    void ChangeCellType(CellType* NewCellType);
    void ChangeEvent(Event* NewEvent);
    void ChangeCellIcon(char NewIcon);
    void ChangeIconToStandart();
};

#endif