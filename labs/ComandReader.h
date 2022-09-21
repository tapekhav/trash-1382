#ifndef GAME_COMANDREADER_H
#define GAME_COMANDREADER_H
#include "string"

#include "MediatorObject.h"

class ComandReader: public MediatorObject{
public:
    ComandReader();
    void readInput();

    unsigned int getFieldWidth() const;
    unsigned int getFieldHeight() const;
    unsigned int getPlayerPositionX() const;
    unsigned int getPlayerPositionY() const;
    char getWay() const;
private:
    void readMove();
    void readField();
    unsigned int checkUIData(const std::string& input);
    bool isNumber(const std::string& s);

    void setWidth(unsigned int width);
    void setHeight(unsigned int height);

    unsigned int fieldWidth;
    unsigned int fieldHeight;
    unsigned int playerPositionX;
    unsigned int playerPositionY;
    char move;
};


#endif
