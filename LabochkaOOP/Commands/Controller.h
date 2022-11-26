//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_CONTROLLER_H
#define UNTITLED48_CONTROLLER_H

#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "../LOG/LogsInfo/Structs.h"
#include "../LOG/LogsInfo/LogOutInfo.h"
#include "../Persons/Person.h"
#include "../LOG/Logs/LogsLvlGame.h"


class Controller{
private:
    Person person;
    Field field;
    FieldView field_view;
public:
    explicit Controller();

    bool win_game();
    bool death_person();

    void set_field(int w, int h);
    void set_field_base();
    void set_step(CONTROL step);

    void print_field();
    void print_stats();

};



#endif //UNTITLED48_CONTROLLER_H
