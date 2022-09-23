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
    std::pair<int, int> playerPosition;
    std::vector<std::vector<Cell>> field;
public:
    Field(unsigned int width = MINWIDTH,
          unsigned int height = MINHEIGHT,
          unsigned int playerPositionX = 0,
          unsigned int playerPositionY = 0);
    Field(const Field& fieldObj);
    void swap(Field &fieldObj);
    Field& operator=(const Field& fieldObj);
    Field(Field&& fieldObj);
    Field& operator=(Field&& filedObj);

    void setField();
    void movePlayer(Player::STEP step);

    unsigned int getWidth() const;
    unsigned int getHeight() const;


    const Cell &getCell(unsigned int h, unsigned int w) const;
};


#endif