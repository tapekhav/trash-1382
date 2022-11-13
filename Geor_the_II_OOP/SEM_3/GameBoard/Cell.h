#pragma once
#include <cmath>
#include "../Events/CellEvent.h"
class Cell{
    private:
        CellEvent *event;
        bool passable;
    public:
        Cell(bool pass); //сделано; проверенно
        Cell(); //сделано; проверенно
        Cell(const Cell& c); //сделано; проверенно -- конструктор коприрования
        Cell(Cell&& c); //сделано; проверенно -- конструктор перемещения
        Cell& operator=(const Cell& c); //сделано; проверенно -- оператор присваивания копирования
        Cell& operator=(Cell&& c); //сделано; проверенно -- оператор приваивания перемещения
        bool operator==(const Cell& c);
        bool operator!=(const Cell& c);
        CellEvent *get_event(); //сделано
        bool is_passable(); //сделано; проверенно
        void set_passable(bool new_passable); //сделано; проверенно
        void set_event(CellEvent *e);
};