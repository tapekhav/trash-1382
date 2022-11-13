#include "Cell.h"
Cell::Cell(bool pass):passable(pass), event(nullptr){}
Cell::Cell():passable(true), event(nullptr){}
Cell::Cell(const Cell& c){
    passable = c.passable;
    event = c.event;
} //конструктор коприрования
Cell::Cell(Cell&& c){
    std::swap(passable, c.passable);
    std::swap(event, c.event);
} //конструктор перемещения
Cell& Cell::operator=(const Cell& c){
    if(this != &c){
        passable = c.passable;
        event = c.event;
    }
    return *this;
} //оператор присваивания копирования
Cell& Cell::operator=(Cell&& c){
    if(this != &c){
        std::swap(passable, c.passable);
        std::swap(event, c.event);
    }
    return *this;
}
bool Cell::operator==(const Cell& c){
    if(event == c.event && passable == c.passable){
        return true;
    }
    return false;
}
bool Cell::operator!=(const Cell& c){
    return !(this->operator==(c));
}
CellEvent *Cell::get_event(){
    return event;
}
bool Cell::is_passable(){
    return passable;
}
void Cell::set_passable(bool new_passable){
    passable = new_passable;
}
void Cell::set_event(CellEvent *e){
    event = e;
}
