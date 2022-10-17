#include "Cell.h"


Cell::Cell(CellType* StartCellType, bool StartPassable, char StartIcon, Event* StartCellEvent):
    CurCellType(StartCellType), Passable(StartPassable), CurIcon(StartIcon), CurCellEvent(StartCellEvent) {};

Cell::Cell(const Cell& obj): Cell(obj.CurCellType, obj.Passable,obj.CurIcon,obj.CurCellEvent){}

Cell &Cell::operator= (Cell const &other){
    if(this == &other)
        return *this;
    this->CurIcon = other.CurIcon;
    this->CurCellType = other.CurCellType;
    this->Passable = other.Passable;
    return *this; 
}

CellType* Cell::ShowCellType(){
    return this->CurCellType;
}

char Cell::ShowCurIcon(){
    return this->CurIcon; 
}

bool Cell::ShowPassable(){
    return this->Passable;
}

bool Cell::ActivationCheck(){
    return this->CurCellEvent;
}

void Cell::ChangeEvent(Event* NewEvent){
    this->CurCellEvent = NewEvent;
}

void Cell::ChangeCellIcon(char NewIcon){
    CurIcon = NewIcon;
}

void Cell::ChangeIconToStandart() {
    if (auto Type = dynamic_cast<CellTypeStone *>(CurCellType))
        CurIcon = '#';
    if (auto Type = dynamic_cast<CellTypeLand *>(CurCellType))
        CurIcon = '.';
}

void Cell::ChangeCellType(CellType* NewCellType){
    this->CurCellType = NewCellType;
}
