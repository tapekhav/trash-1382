#ifndef LABS_FIELD_H
#define LABS_FIELD_H

class Cell;

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>
#include "Cell.h"
#include "../Characters/Player.h"
#include "../Control/Observer/Observer.h"
#include "../Control/Observer/Observable.h"
#include "../Events/ChangePlayer/Box.h"
#include "../Events/ChangePlayer/Enemy.h"
#include "../Events/ChangePlayer/Heal.h"
//#include "../Events/ChangeField/NewLevel.h"

class Field : public Observable {
public:
    explicit Field(int width = 10, int height = 10);
    Field(const Field &other);
    Field& operator=(const Field &other);
    Field(Field&& other);
    Field& operator=(Field&& other);

    void generate_enemy();
    void make_field();
    void change_player_pos(Player &player, Player::STEP s);

    int get_height() const;
    int get_width()  const;
    Cell get_cur_cell(int x, int y) const;
private:
    void swap(Field& other);

    std::vector<std::vector<Cell>> field;
    int height;
    int width;
    std::pair<int, int> player_location;
};

#endif