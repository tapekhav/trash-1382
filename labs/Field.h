#ifndef LABS_FIELD_H
#define LABS_FIELD_H

#include <iostream>
#include <algorithm>
#include "Cell.h"
#include "CellView.h"
#include "Player.h"
#include <vector>
#include <random>
#include <cmath>

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
    void swap(Field& other);
    int get_height() const;
    int get_width()  const;
    std::vector<std::vector<Cell>> get_field() const;
private:
    std::vector<std::vector<Cell>> field;
    int height, width;
    std::pair<int, int> player_location;
};

#endif //LABS_FIELD_H