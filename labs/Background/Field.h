#ifndef LABS_FIELD_H
#define LABS_FIELD_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>
#include "Cell.h"
#include "CellView.h"
#include "../Characters/Player.h"

class Field {
public:
    explicit Field(int width = 0, int height = 0);
    ~Field() = default;
    Field(const Field &other);
    Field& operator=(const Field &other);
    Field(Field&& other) noexcept;
    Field& operator=(Field&& other) noexcept;

    void make_field();
    void change_player_pos(Player::STEP s);

    int get_height() const;
    int get_width()  const;
    std::vector<std::vector<Cell>> get_field() const;
private:
    bool check_cell(Cell cell) const;
    void swap(Field& other);

    std::vector<std::vector<Cell>> field;
    int height;
    int width;
    std::pair<int, int> player_location;
};

#endif //LABS_FIELD_H