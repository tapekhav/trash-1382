#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H


#include "MediatorObject.h"
#include "../Background/Field/FieldView.h"
#include "../Background/Field/Field.h"
#include "../Characters/Player.h"
#include "../Background/Cell/CellView.h"
#include "Model.h"

class Controller: public MediatorObject{
public:
    Controller();
    void notify(char&) final;
    void createField(std::pair<int, int>);
private:
    Model model;
    FieldView fieldView;
};


#endif
