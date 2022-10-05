#ifndef FIELD_H
#define FIELD_H

#include "../Player/Player.h"
#include "Cell.h"
#include "../Support/Enum.h"
#include <vector>

struct Coords{
    int xCoord, yCoord;
};

class Field
{
private:
    int height, width;
    Coords pCoords; 
    Player character;
    std::vector <std::vector<Cell>> CurField;
    
public:

    Field(int height = Enum::DEFAULT_HEIGHT_OF_FIELD, int width = Enum::DEFAULT_WIDTH_OF_FIELD);

    Field (const Field &obj);
    Field (Field &&obj);
    Field &operator =(Field const &other);

    int ShowHeight(); 
    int ShowWidth();
    Coords ShowPlayerCoords();
    std::vector <std::vector<Cell>> ShowCurField();

    void PlayersMove(Enum::Direction direction);
    void FixFieldSettings();

    void ChangeIconToStandart(Coords CellCoords);
};

#endif