//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_FIELD_H
#define UNTITLED48_FIELD_H
#include "vector"
#include "../Cell/Cell.h"
#include "../Persons/Person.h"
#include "random"
#include "../EventsPerson//EventXp.h"
#include "../EventsPerson//EventHp.h"
#include "../EventsPerson//EventDmg.h"
//#include "../EventsField/EventChangeMap.h"
class Field {
private:
    Person person;
    std::vector<std::vector<Cell>> field;
    int height;
    int width;
    std::pair<int, int> person_loc;

public:
    void swap(Field &other);
    explicit Field(int width = 10, int height = 15);

    Field(const Field &other);
    Field& operator=(const Field &other);
    Field(Field&& other);
    Field& operator=(Field&& other);


    bool check_cell(Cell cell)const;
    void change_person_pos(Person::STEP s);
    void make_field();
    Person get_person() const;
    int get_height() const;
    int get_width() const;

    std::vector<std::vector<Cell>> get_field() const;



};


#endif //UNTITLED48_FIELD_H
