//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_CONTROLLER_H
#define UNTITLED48_CONTROLLER_H

#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "../LogsInfo/Structs.h"
#include "../LogsInfo/LogOutInfo.h"
#include "../Persons/Person.h"
#include "../Logs/LogsLvlGame.h"
class Controller{
private:
    Person person;
    Field field;
    FieldView field_view;
    LogOutInfo *log_out_info{};
public:
    explicit Controller(LogOutInfo *info = nullptr);
    bool win_game();
    bool death_person();

    void set_field(int w, int h);
    void set_field_base();
    void set_step(Person::STEP step);

    void print_field();
    void print_stats();
};



#endif //UNTITLED48_CONTROLLER_H
