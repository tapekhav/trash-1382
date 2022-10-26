#include <iostream>
#include <vector>
#include <random>
#include "Field.h"
#include "Cell.h"
#include "../Characters/Player.h"
#include "../Events/PlayerEvents/PlayerEvent.h"
#include "../Events/EventBuilder.h"
#include "../Events/FieldEvents/FieldEvent.h"
#include "../Events/FieldEvents/Collapse.h"
#include "../Events/FieldEvents/Decrease.h"
#include "../Events/FieldEvents/Increase.h"
#include "../Events/PlayerEvents/Enemy.h"
#include "../Events/PlayerEvents/GetCoin.h"
#include "../Events/PlayerEvents/Heal.h"
#include "../Events/GameRulesEvents/Win.h"
#include "../Events/GameRulesEvents/Lose.h"
//#include "../Events/GameRulesEvents/"

Field::Field(int width, int height) {
    if (width >= 10 && width <= 40)
        this->width = width;
    else if (width >= 40)
        this->width = 40;
    else
        this->width = 10;
    if (height >= 10 && height <= 40)
        this->height = height;
    else if (height >= 40)
        this->height = 40;
    else
        this->height = 10;
    this->player_x = 1;
    this->player_y = 1;
    this->height_inc = 0;
    this->width_inc = 0;
}

void Field::create_field(Player *player) {
    update_height();
    update_width();
    this->field = std::vector < std::vector < Cell >> (height, std::vector<Cell>(width));
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            this->field.at(y).at(x) = Cell();
        }
    }
    update_events(player);
}

void Field::update_events(Player *player) {
    EventBuilder builder(this, player);
    builder.update_events();
}

Field::Field(const Field &other) {
    this->width = other.width;
    this->height = other.height;
    this->player_x = other.player_x;
    this->player_y = other.player_y;
    std::vector <std::vector<Cell>> map(this->height, std::vector<Cell>(this->width));
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

Field::Field(Field &&other)

noexcept {
this->
swap(other);
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

Field &Field::operator=(Field &&other)

noexcept {
if (this != &other)
this->
swap(other);
return *this;
}

bool Field::move_player(Player *player, int x, int y) {
    EventBuilder builder(this, player);
    int new_x = get_new_x(x);
    int new_y = get_new_y(y);
    int prev_x = this->player_x;
    int prev_y = this->player_y;
    if (this->field[new_y][new_x].get_pass()) {
        this->player_x = new_x;
        this->player_y = new_y;
        this->get_cell(new_x, new_y).set_player(true);
        notify();
        Cell cl = this->field.at(new_y).at(new_x);
        Event *ev = cl.get_event();
        Event *wn = builder.create_WinEvent();
        Event *ls = builder.create_LoseEvent();
        auto *pl = dynamic_cast<PlayerEvent *> (ev);
        auto *fl = dynamic_cast<FieldEvent *> (ev);
        if (pl || fl) {
            ev->execute();
            if (pl && (wn->execute() || ls->execute())) {
                return false;
            }
        }
        update_player(prev_x, prev_y);
    }
    return true;
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
        new_x = this->width - 1;
    else if (new_x == this->width)
        new_x = 1;
    return new_x;
}

int Field::get_new_y(int y) const {
    int new_y = this->player_y + y;
    if (new_y == -1)
        new_y = this->height - 1;
    else if (new_y == this->height)
        new_y = 0;
    return new_y;
}

void Field::update_player(int prev_x, int prev_y) {
    if (prev_x < this->width && prev_y < this->height) {
        this->get_cell(prev_x, prev_y).set_event(nullptr);
        this->get_cell(prev_x, prev_y).set_player(false);
    }
}

Cell &Field::get_cell(int x, int y) {
    return this->field[y][x];
}

void Field::add_width(int wd) {
    this->width_inc += wd;
}

void Field::add_height(int hg) {
    this->height_inc += hg;
}

int Field::get_width() const {
    return this->width;
}


int Field::get_height() const {
    return this->height;
}

int Field::get_width_inc() const {
    return this->width_inc;
}

int Field::get_height_inc() const {
    return this->height_inc;
}

void Field::update_height() {
    int new_height = this->height + this->height_inc;
    if (new_height > 10 && new_height < 40) {
        this->height = new_height;
    } else if (new_height < 10) {
        this->height = 10;
    } else {
        this->height = 40;
    }
    update_coords();
    this->height_inc = 0;
}

void Field::update_width() {
    int new_width = this->width + this->width_inc;
    if (new_width > 10 && new_width < 40) {
        this->width = new_width;
    } else if (new_width < 10) {
        this->width = 10;
    } else {
        this->width = 40;
    }
    update_coords();
    this->width_inc = 0;
}

void Field::update_coords() {
    if (this->player_y >= (this->height - 1)) {
        this->player_y = this->height - 2;
    }
    if (this->player_x >= (this->width - 1)) {
        this->player_x = this->width - 2;
    }
}

void Field::set_cell(int x, int y, Cell cell) {
    field.at(y).at(x) = cell;
}

