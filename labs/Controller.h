#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H


#include "MediatorObject.h"
#include "FieldView.h"
#include "Field.h"
#include "Player.h"

class Controller: public MediatorObject{
public:
    Controller() = default;
    void createField(unsigned int height, unsigned int width);
    void movePlayerPosition(char c);
    void printFieldView() const;
private:
    Field field;
    FieldView fieldView;
    Player player;
};


#endif
