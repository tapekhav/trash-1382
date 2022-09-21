#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H


#include "MediatorObject.h"
#include "FieldView.h"
#include "Field.h"
#include "Player.h"

class Controller: public MediatorObject{
public:
    Controller();
    void createField(unsigned int height, unsigned int width, unsigned playerPositionX, unsigned int playerPositionY);
    void setPlayerPosition(unsigned int playerPositionX, unsigned int playerPositionY);
    unsigned int getPlayerPositionX() const;
    unsigned int getPlayerPositionY() const;
    void printFieldView() const;
private:
    Field field;
    FieldView fieldView;
    Player player;


};


#endif
