//
// Created by corvussharp on 21.09.22.
//

#include "Field.h"
#include "iostream"

    void Field::swap(Field &other) {
        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(field, other.field);
        std::swap(person_loc, other.person_loc);
        std::swap(person,other.person);
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




    Field::Field(int width, int height) : width(width), height(height), person_loc({0, 0}), person{1,1,1}{
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

    Field::Field(Field&& other){ // конструктор перемещаем объект
        this->swap(other);
    }


    bool  Field::check_cell(Cell cell) const {
        if(cell.get_obj() == Cell::BLOCK) return false;
        return true;
    }
/*
    bool  Field::set_hp(Cell cell){
        if(cell.get_obj() != Cell::HP){
            return false;
        }
        person.set_hp(person.get_hp()+10);
        return true;
    }
    */

   
    void  Field::change_person_pos(Person::STEP s) {
        field.at(person_loc.second).at(person_loc.first).set_obj(Cell::STANDARD);
        auto tmp = person_loc;

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

        if (check_cell(field.at(tmp.second).at(tmp.first))) {
            person_loc = tmp;
        }
        //set_hp(field.at(person_loc.second).at(person_loc.first));
        //set_dmg(field.at(person_loc.second).at(person_loc.first));
        //set_xp(field.at(person_loc.second).at(person_loc.first));
        field.at(person_loc.second).at(person_loc.first).update(person);

        field.at(person_loc.second).at(person_loc.first).set_obj(Cell::PERSON);
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



    void  Field::make_field() {
        field.at(0).at(0).set_obj(Cell::PERSON);
        for(int i = 0; i != height; ++i) {
            int value; if(i == 0){
                value = 1;
            } else value = 0;

            for(int j = value; j != width; ++j) {
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);
                auto* eventXp = new EventXp;
                auto* eventHp = new EventHp;
                auto* eventDmg = new EventDmg;
              //  auto* eventFieldChange = new EventFieldChange;
             //  auto* eventChangeMap = new EventFieldChange;


                switch(dist(rng)) {
                    case 1:
                        field.at(i).at(j).set_obj(Cell::BOX);
                        field.at(i).at(j).set_event_person(eventXp);
                        break;
                    case 2:
                        field.at(i).at(j).set_obj(Cell::HP);
                        field.at(i).at(j).set_event_person(eventHp);
                        break;
                    case 3:
                        field.at(i).at(j).set_obj(Cell::BLOCK);
                        break;
                    case 4:
                        field.at(i).at(j).set_obj(Cell::STANDARD);
                        break;
                    case 5:
                        field.at(i).at(j).set_obj(Cell::DMG);
                        field.at(i).at(j).set_event_person(eventDmg);
                        break;
                    case 6:
                        field.at(i).at(j).set_obj(Cell::CHANGEMAP);
                       // field.at(i).at(j).set_event_field(eventFieldChange);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    Person Field::get_person() const{
        return person;
    }


