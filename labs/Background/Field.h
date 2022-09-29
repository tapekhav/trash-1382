#ifndef GAME_FIELD_H
#define GAME_FIELD_H
#include "vector"
#include "Cell.h"
#include "iostream"
#include "../Characters/Player.h"

#define MINHEIGHT 10
#define MINWIDTH 10


class Field{
private:
    unsigned int height;
    unsigned int width;
    std::pair<int, int> playerPosition;
    std::vector<std::vector<Cell*>> field;
public:
    Field(unsigned int width = MINWIDTH,
          unsigned int height = MINHEIGHT,
          unsigned int playerPositionX = 0,
          unsigned int playerPositionY = 0);

    Field(const Field&);
    void swap(Field&);
    Field& operator=(const Field&);
    Field(Field&&);
    Field& operator=(Field&&);

    void setField();
    void movePlayer(Player::STEP);

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const Cell& getCell(unsigned int, unsigned int) const;
};


#endif