#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H


#include "MediatorObject.h"
#include "../Background/FieldView.h"
#include "../Background/Field.h"
#include "../Characters/Player.h"
#include "../Background/CellView.h"

class Controller: public MediatorObject{
public:
    void createField(unsigned int height, unsigned int width);
    void movePlayerPosition(char c);
    void printFieldView() const;
    Controller &operator=(const Controller&);
    void start() final;
private:
    Field field;
    FieldView fieldView;
    Player player;
};


#endif
