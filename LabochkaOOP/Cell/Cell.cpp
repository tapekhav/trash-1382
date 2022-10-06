//
// Created by corvussharp on 21.09.22.
//

#include "Cell.h"
#include "../EventsPerson//EventPerson.h"

    Cell::Cell() : object(STANDARD), player_loc(false){

    };
Cell::OBJECT Cell::get_obj() const {
    return object;
}

    void Cell::update(Person& person){
        if(check_player()) event->doing(person);
    }

    void Cell::set_event_person(EventPerson* event_){
        delete this->event;
        this->event = event_;
    }

    void Cell::set_obj(OBJECT obj){
        this->object = obj;
    }
    void Cell::set_person_loc(bool loc){
        this->player_loc = loc;
    }
    bool Cell::check_player()const{
        return player_loc;
    }
