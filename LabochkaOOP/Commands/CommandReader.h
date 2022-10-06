//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_COMMANDREADER_H
#define UNTITLED48_COMMANDREADER_H

#include "../Persons/Person.h"
#include "iostream"
class CommandReader{
private:
    Person::STEP step;

    int height, width;

    char sym;

public:
    void set_size();
    void check_step();
    int arg_error();

    bool valid_arg(int a);

    int get_height() const;
    int get_width()const;

    char get_sym()const;
    char field_choice();

    Person::STEP get_step() const;


};



#endif //UNTITLED48_COMMANDREADER_H
