#pragma once
#include <vector>
#include <map>
#include <cmath>
#include "Cell.h"
#include "../CommandReader/CommandOperand.h"
class Field {
private:
    unsigned int width;
    unsigned int length;
    std::pair <long int, long int> coord;
    std::vector <std::vector <Cell>> map;
    CellEvent *event_for_null;
public:
    Field(unsigned int w, unsigned int l, std::pair <long int, long int> c); //сделано; проверенно
    Field(unsigned int w, unsigned int l, long int x, long int y); //сделано; проверенно
    Field(unsigned int w, unsigned int l); //сделано; проверенно
    Field(unsigned int w, unsigned int l, std::pair <long int, long int> c, CellEvent *e);
    Field(unsigned int w, unsigned int l, long int x, long int y, CellEvent *e);
    Field(unsigned int w, unsigned int l, CellEvent *e);
    Field(); //сделано; проверенно
    Field(const Field& f); //сделано; проверенно
    Field(Field&& f); //сделано; проверенно
    Field& operator=(const Field& f); //сделано; проверенно
    Field& operator=(Field&& f); //сделано; проверенно
    bool operator==(const Field& f);
    bool operator!=(const Field& f);
    bool move_player(CommandOperand d);
    GameStatus trigger_cell();
    void set_coord(std::pair <long int, long int> coord);
    void set_coord(long int x, long int y);
    void set_event_for_null(CellEvent *e);
    CellEvent *get_event_for_null();
    std::pair <long int, long int> get_coord();
    Cell *get_player_cell();
    Cell *get_cell(std::pair <long int, long int> coord);  //сделано; проверенно
    Cell *get_cell(long int x, long int y);  //сделано; проверенно
    unsigned int get_width(); //сделано; проверенно
    unsigned int get_length(); //сделано; проверенно
};