#ifndef LAB2_CONTROLLER_H
#define LAB2_CONTROLLER_H


#include <utility>
#include "MediatorObject.h"
#include "../Background/Data/Model.h"
#include "../Background/Field/View/FieldView.h"

class Controller: public MediatorObject{
public:
    Controller(std::pair<int, int>);
    void notify(char&) final;
private:
    Model model;
    FieldView fieldView;
};


#endif
