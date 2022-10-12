#ifndef LABS_FIELD_H
#define LABS_FIELD_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "CellType/CellWall.h"
#include "CellType/CellBox.h"
#include "CellType/CellHeal.h"
#include "CellType/CellKey.h"
#include "CellType/CellNewLevel.h"
#include "CellType/CellStandard.h"
#include "CellType/CellTrap.h"


class Field : public Observable {
public:
    explicit Field(int width = 10, int height = 10);
    Field(const Field &other);
    ~Field();
    Field& operator=(const Field &other);
    Field(Field&& other);
    Field& operator=(Field&& other);

    void generate_keys();
    void make_field();
    CellType* generate_cell();

    Event* change_player_pos(Player::STEP s);
    std::pair<int, int> get_player_location() const;

    int get_height() const;
    int get_width()  const;
    CellType* get_cur_cell(int x, int y) const;

    void clear_field();
private:
    void swap(Field& other);

    std::vector<std::vector<CellType*>> field;
    int height;
    int width;
    std::pair<int, int> player_location;
};

#endif