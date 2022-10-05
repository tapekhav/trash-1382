#include "Field.h"

Field &Field::operator= (Field const &other){
    if(this == &other)
        return *this;

    for(int i = 0; i < height; ++i)
        CurField[i].clear();
    CurField.clear();

    this->height = other.height;
    this->width = other.width;

    for(int i = 0; i < height; ++i)
        CurField.push_back(other.CurField[i]); 

    this->pCoords = other.pCoords;
    this->character = other.character;
    return *this;
}

Field::Field (const Field &obj): Field(obj.height,obj.width){
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            this->CurField[i][j] = obj.CurField[i][j];
    this->pCoords = obj.pCoords;
    this->character = obj.character; 
}

Field::Field (Field &&obj): Field(obj.height,obj.width){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j)
            this->CurField[i][j] = obj.CurField[i][j];
        obj.CurField[i].clear();
    }
    obj.CurField.clear();
    this->pCoords = obj.pCoords;
    obj.pCoords.xCoord = -1;
    obj.pCoords.yCoord = -1;
    this->character = obj.character;
}

int Field::ShowHeight(){
    return height;
}

int Field::ShowWidth(){
    return width;
}

Coords Field::ShowPlayerCoords(){
    return pCoords;
}

std::vector <std::vector<Cell>> Field::ShowCurField(){
    return CurField; 
}

void Field::FixFieldSettings(){
    if(height<1)
        height = Enum::DEFAULT_HEIGHT_OF_FIELD;
    else if(height>35)
        height = 35;
    if(width<1)
        width = Enum::DEFAULT_WIDTH_OF_FIELD;
    else if(width>50)
        width = 50;
}

Field::Field(int _height, int _width):height(_height), width(_width){
    FixFieldSettings();
    for(int i = 0; i<height; ++i){
        CurField.push_back(std::vector<Cell>(width));
        for(int j = 0; j<width; ++j)
            CurField.back().emplace_back(Cell());
    }
    pCoords.xCoord = width/2;
    pCoords.yCoord = height/2;
    CurField[pCoords.yCoord][pCoords.xCoord].ChangeCellIcon('P');
}

void Field::ChangeIconToStandart(Coords CellCoords){
    CurField[CellCoords.yCoord][CellCoords.xCoord].ChangeIconToStandart();
}

void Field::PlayersMove(Enum::Direction direction){
    Coords PrevCoords = pCoords;
    CurField[pCoords.yCoord][pCoords.xCoord].ChangeIconToStandart();
    switch (direction)
    {
        case Enum::UP:
        pCoords.yCoord -1 >= 0 ? --pCoords.yCoord : pCoords.yCoord = height-1;
        break;

        case Enum::DOWN:
        pCoords.yCoord + 1 < height ? ++pCoords.yCoord : pCoords.yCoord = 0;
        break;

        case Enum::LEFT:
        pCoords.xCoord - 1 >= 0 ?  --pCoords.xCoord : pCoords.xCoord = width - 1;
        break;
    
        case Enum::RIGHT:
        pCoords.xCoord + 1 < width ? ++pCoords.xCoord : pCoords.xCoord = 0;
        break;
    }

    if(!CurField[pCoords.yCoord][pCoords.xCoord].ShowPassable())
        pCoords=PrevCoords;
        
    CurField[pCoords.yCoord][pCoords.xCoord].ChangeCellIcon('P'); 

    if(CurField[pCoords.yCoord][pCoords.xCoord].ActivationCheck())
        return; 
}