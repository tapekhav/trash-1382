//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_CELL_H
#define UNTITLED48_CELL_H
#include "../EventsPerson//EventPerson.h"

class Cell{
public:
    enum OBJECT{
        STANDARD,
        BLOCK,
        HP,
        PERSON,
        BOX,
        DMG,
        CHANGEMAP
    };
    explicit Cell();

    OBJECT get_obj() const;
    void update(Person& person);
    void set_event_person(EventPerson* event_);

    void set_obj(OBJECT obj);
    void set_person_loc(bool loc);

    bool check_player()const;

private:

    OBJECT object;
    bool player_loc;
    EventPerson* event;
};


#endif //UNTITLED48_CELL_H
