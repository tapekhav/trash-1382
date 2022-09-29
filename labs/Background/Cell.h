#ifndef GAME_CELL_H
#define GAME_CELL_H


#include "Event.h"


//написать конструктор пкопирования/рисваивания для смены клетки в поле
class Cell{
public:
    virtual bool isPassable() const;
    void setEvent(Event* event);
    void callEvent();
    enum Type{
        Grass,
        Wall,
        Player,
        Empty
    };
    Cell::Type getType() const;
protected:
    Event* event = nullptr;
    Type type = Type(Empty);
};


#endif //GAME_CELL_H
