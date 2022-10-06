//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_CONTROLLER_H
#define UNTITLED48_CONTROLLER_H

#include "../Field/Field.h"
#include "../Field/FieldView.h"

class Controller{
private:

    Field field;
    FieldView field_view;
public:
    Controller();
    Field get_field();

    void set_field(int w, int h);
    void set_field_base();
    void set_step(Person::STEP step);
    void print_field();
    void print_stats();
};



#endif //UNTITLED48_CONTROLLER_H
