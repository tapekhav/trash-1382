//
// Created by corvussharp on 21.09.22.
//

#include "Field.h"
#include "iostream"
#include "../Events/EventsField/EventChangeField.h"

    void Field::swap(Field &other) {
        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(field, other.field);
        std::swap(person_loc, other.person_loc);
        std::swap(person,other.person);
    }
    void Field::trig_win(){
    trigWin = true;
}
    void Field::update_field( std::pair<int, int> person_loc){
    this->field.at(person_loc.second).at(person_loc.first).set_event(nullptr);
}


    int  Field::get_height() const {
        return height;
    }

    int  Field::get_width() const {
        return width;
    }

    std::vector<std::vector<Cell>>  Field::get_field() const  {
        return field;
    }
    bool Field::level_check_passab(){
        if(person.get_lvl() >= 2){
            return true;
        } return false;
    };
    bool Field::get_win()const{
    return trigWin;
}
    bool Field::check_box_win(){
        int count = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(dynamic_cast<EventXp*>(field.at(i).at(j).get_event())!= nullptr){
                    count++;
                }
            }
        }
        if (count == 0){
            return true;
        }
        return false;
    }

    Field& Field::operator=(const Field &other) {
    if (this != &other) // не пытаемся ли мы присвоить объект сам в себя
        Field(other).swap(*this); //создаем временный объект(все поля совпадают с азер), меняемся с ним данными

    return *this;
}
    Field& Field::operator=(Field&& other) {
        if (this != &other)
            this->swap(other); // меняем местами текущий и other
        return *this;
    }
    Field::Field(int width, int height) : trigWin(false),width(width), height(height), person_loc({0, 0}), person{1,1,1, 1}{
        for(int i = 0; i != height; ++i) {
            field.emplace_back(); // инициализация полей
            for(int j = 0; j != width; ++j) {
                field.at(i).emplace_back();
            }
        }
    }
    Field::Field(const Field &other): width(other.width), height(other.height), person_loc(other.person_loc),person(other.person) {
        for(size_t i = 0; i != height; ++i) {
            field.emplace_back();
            for(size_t j = 0; j != width; ++j) {
                field.at(i).push_back(other.field.at(i).at(j));
            }
        }
    }
    Field::Field(Field&& other) { // конструктор перемещаем объект
        this->swap(other);
    }

    Cell &Field::getCell(std::pair<int, int> position){
        return field.at(position.second).at(position.first);
    }



    void Field::spawn_new_events() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution gen_height(1, height - 1);
        std::uniform_int_distribution gen_width(0, width - 1);

        std::pair<int, int> pair1 = {gen_height(rng), gen_width(rng)};

        auto *spawnEventsBlock = new EventChangeField;

        field.at(pair1.first).at(pair1.second).set_event(spawnEventsBlock);
        field.at(pair1.first).at(pair1.second).set_passab(false);
    }

    void Field::spawn_box(){
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution gen_height(1, height - 1);
        std::uniform_int_distribution gen_width(0, width - 1);

        std::pair<int, int> pair1 = {gen_height(rng), gen_width(rng)};
        std::pair<int, int> pair2 = {gen_height(rng), gen_width(rng)};

    while (pair1 == pair2)
        pair2 = {gen_height(rng), gen_width(rng)};

    auto *boxXp = new EventXp;
    auto *boxXp1 = new EventXp;

    delete  field.at(pair1.first).at(pair1.second).get_event();
    delete field.at(pair2.first).at(pair2.second).get_event();

    field.at(pair1.first).at(pair1.second).set_event(boxXp);
    field.at(pair2.first).at(pair2.second).set_event(boxXp1);
}

    void Field::spawn_win(){
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution gen_height(1, height - 1);
        std::uniform_int_distribution gen_width(0, width - 1);

        std::pair<int, int> pair1 = {gen_height(rng), gen_width(rng)};

        auto *boxExit = new EventWin;

        field.at(pair1.first).at(pair1.second).set_event(boxExit);
        field.at(pair1.first).at(pair1.second).set_passab(false);
    }


    Person Field::get_person() const{
        return person;
    }
        void Field::callEvent(Person *person, std::pair<int, int> person_loc) {
            if (dynamic_cast<EventPerson*>(getCell(person_loc).get_event())){
            getCell(person_loc).update(person);
        }
        else if(dynamic_cast<EventField*>(getCell(person_loc).get_event())){
            getCell(person_loc).update(this);
        }
    }


    void  Field::spawn_events() {
        field.at(0).at(0).set_passab(true);
        for (int i = 0; i != height; ++i) {
            int value;
            if (i == 0) {
                value = 1;
            } else value = 0;
            for (int j = value; j != width; ++j) {
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);

                switch (dist(rng)) {
                    case 1: {
                        auto *xp = new EventXp;
                        field.at(i).at(j).set_event(xp);
                        break;
                    }
                    case 2: {
                        auto *hp = new EventHp;
                        field.at(i).at(j).set_event(hp);
                        break;
                    }
                    case 5: {
                        auto *dmg = new EventDmg;
                        field.at(i).at(j).set_event(dmg);
                        break;
                    }
                    default:
                        break;
                }

            }
        }
    }


void  Field::change_person_pos(Person::STEP s) {
        auto tmp = person_loc;
        field.at(person_loc.second).at(person_loc.first).set_person_in(false);

        switch(s) {
            case Person::UP:
                tmp.second--;
                break;
            case Person::DOWN:
                tmp.second++;
                break;
            case Person::LEFT:
                tmp.first--;
                break;
            case Person::RIGHT:
                tmp.first++;
                break;
            default:
                break;
        }

        tmp.first = tmp.first % width;
        tmp.second = tmp.second % height;

        if (tmp.first < 0) tmp.first += width;
        if (tmp.second < 0) tmp.second += height;


        if(field.at(tmp.second).at(tmp.first).get_passab() || level_check_passab() ||
        (dynamic_cast<EventWin*>(field.at(tmp.second).at(tmp.first).get_event()) && check_box_win())){
            person_loc = tmp;
            callEvent(&person,person_loc);
            update_field(person_loc);
        }

        field.at(person_loc.second).at(person_loc.first).set_person_in(true);
    }


    void  Field::make_field() {
        field.at(0).at(0).set_person_in(true);
        field.at(0).at(0).set_passab(true);
        spawn_box();
        spawn_new_events();
        spawn_win();
    for(int i = 0; i != height; ++i) {
            int value; if(i == 0){
                value = 1;
            } else value = 0;
            for(int j = value; j != width; ++j) {
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);
                switch(dist(rng)) {
                    case 2: {
                        auto* hp = new EventHp;
                        if(field.at(i).at(j).get_event() == nullptr) {
                            field.at(i).at(j).set_event(hp);
                        }
                        break;
                    }
                    case 3:{
                        auto *trap = new EventTrap;
                        field.at(i).at(j).set_event(trap);
                    }
                    case 5: {
                        auto *dmg = new EventDmg;
                        if (field.at(i).at(j).get_event() == nullptr) {
                            field.at(i).at(j).set_event(dmg);
                        }
                        break;
                    }
                    default:
                        break;
                }

            }
        }

    }





/*
Field::~Field() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (field.at(i).at(j).get_event() != nullptr) {
                delete field.at(i).at(j).get_event();
            }
        }
    }
}
*/

