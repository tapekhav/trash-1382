#ifndef LABS_FIELD_H
#define LABS_FIELD_H

class Cell;

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "Cell.h"
#include "../Characters/Player.h"
#include "../Logging/Observer.h"
#include "../Logging/Observable.h"
#include "../Events/EventCreator.h"

class Field : public Observable {
public:
    explicit Field(int width = 10, int height = 10);
    ~Field();
    Field(const Field&);
    Field& operator=(const Field&);
    Field(Field&& other);
    Field& operator=(Field&&);

    void generate_walls();
    void delete_walls();
    void make_field(Player&);

    void change_player_location(Player&, Player::STEP);
    std::pair<int, int> get_player_location() const;

    int get_height() const;
    int get_width()  const;
    Cell& get_cur_cell(int, int);
private:
    void swap(Field&);

    std::vector<std::vector<Cell>> field;
    int height;
    int width;
    std::pair<int, int> player_location;
};

#endif