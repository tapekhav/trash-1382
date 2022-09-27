#include <iostream>
#include <vector>
#include <random>
#include "Field.h"
#include "Cell.h"

Field::Field(int width, int height) {
    this->width = width;
    this->height = height;
    this->player_x = 1;
    this->player_y = 1;
}

void Field::create_field() {
    std::vector<std::vector<Cell>> map(this->height, std::vector<Cell>(this->width));
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            if ((x == 0 || x == (this->width - 1)) && y != 0 && y != (this->height - 1))
                map[y][x] = Cell(Cell::wall_vert);
            else if (y == 0 || y == (this->height - 1))
                map[y][x] = Cell(Cell::wall_hor);
            else {
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);
                switch (dist(rng)) {
                    case 1:
                        map[y][x] = Cell(Cell::enemy);
                        break;
                    case 2:
                        map[y][x] = Cell(Cell::coin);
                        break;
                    case 3:
                        map[y][x] = Cell(Cell::heal);
                        break;
                    case 4:
                        map[y][x] = Cell(Cell::fix);
                        break;
                    default:
                        map[y][x] = Cell(Cell::empty);
                        break;
                }
            }
        }
    }
    map[this->player_y][this->player_x] = Cell(Cell::player);
    this->field = map;
}

Field::Field(const Field &other) {
    this->width = other.width;
    this->height = other.height;
    this->player_x = other.player_x;
    this->player_y = other.player_y;
    std::vector<std::vector<Cell>> map(this->height, std::vector<Cell>(this->width));
    for (int y = 0; y < other.height; y++) {
        for (int x = 0; x < other.width; x++) {
            map[y][x] = other.field[y][x];
        }
    }
    this->field = map;
}


std::vector<int> Field::get_size() const {
    std::vector<int> sizes = {this->width, this->height};
    return sizes;
}

std::vector<std::vector<Cell>> Field::get_field() {
    return this->field;
}

Field::Field(Field &&other) noexcept {
    this->swap(other);
};

void Field::swap(Field &other) {
    std::swap(this->width, other.width);
    std::swap(this->height, other.height);
    std::swap(this->player_x, other.player_x);
    std::swap(this->player_y, other.player_y);
    std::swap(this->field, other.field);
}

Field &Field::operator=(const Field &other) {
    if (this != &other)
        Field(other).swap(*this);
    return *this;
}

Field &Field::operator=(Field &&other) noexcept {
    if (this != &other)
        this->swap(other);
    return *this;
}

bool Field::move_player(int x, int y) {
    int new_x = get_new_x(x);
    int new_y = get_new_y(y);
    int prev_x = this->player_x;
    int prev_y = this->player_y;
    if (this->field[new_y][new_x].get_obj() == Cell::empty) {
        this->player_x = new_x;
        this->player_y = new_y;
        update_player(prev_x, prev_y);
        return true;
    }
    return false;
}

int Field::get_player_x() const {
    return this->player_x;
}

int Field::get_player_y() const {
    return this->player_y;
}

int Field::get_new_x(int x) const {
    int new_x = this->player_x + x;
    if (new_x == 0)
        new_x = this->width - 2;
    else if (new_x == (this->width - 1))
        new_x = 1;
    return new_x;
}

int Field::get_new_y(int y) const {
    int new_y = this->player_y + y;
    if (new_y == 0)
        new_y = this->height - 2;
    else if (new_y == (this->height - 1))
        new_y = 1;
    return new_y;
}

void Field::update_player(int prev_x, int prev_y) {
    this->field[prev_y][prev_x].set_obj(Cell::empty);
    this->field[this->player_y][this->player_x].set_obj(Cell::player);
}









