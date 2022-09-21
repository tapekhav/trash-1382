#ifndef GAME_FIELD_H
#define GAME_FIELD_H
#include "vector"
#include "Cell.h"
#include "Player.h"

#define MINHEIGHT 10
#define MINWIDTH 10



class Field{
private:
    unsigned int height;
    unsigned int width;
    unsigned int playerPositionX;
    unsigned int playerPositionY;
    Player player;
    std::vector<std::vector<Cell>> field;
public:
    Field(unsigned int width = MINWIDTH,
          unsigned int height = MINHEIGHT,
          unsigned int playerPositionX = 0,
          unsigned int playerPositionY = 0);

    void setField();
    void setPlayerPosition(unsigned int playerPositionX, unsigned int playerPositionY);


    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getPlayerPositionX() const;
    unsigned int getPlayerPositionY() const;


    Cell getCell(int h, int w) const;
};


#endif