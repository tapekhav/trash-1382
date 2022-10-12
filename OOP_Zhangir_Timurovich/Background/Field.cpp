#include <iostream>
#include <vector>
#include <random>
#include "Field.h"
#include "Cell.h"
#include "../Characters/Player.h"
#include "../Events/PlayerEvents/PlayerEvent.h"
#include "../Events/FieldEvents/FieldEvent.h"
#include "../Events/FieldEvents/Collapse.h"
#include "../Events/FieldEvents/Decrease.h"
#include "../Events/FieldEvents/Increase.h"
#include "../Events/PlayerEvents/Enemy.h"
#include "../Events/PlayerEvents/GetCoin.h"
#include "../Events/PlayerEvents/Heal.h"
//#include "../Events/GameRulesEvents/"

Field::Field(int width, int height) {
    if (width >= 10)
        this->width = width;
    else
        this->width = 10;
    if (height >= 10)
        this->height = height;
    else
        this->height = 10;
    this->player_x = 1;
    this->player_y = 1;
    this->height_inc = 0;
    this->width_inc = 0;
}

void Field::create_field() {
    CellType *cl;
    Event *ev = nullptr;
    update_height();
    update_width();
    this->field = std::vector<std::vector<Cell>>(this->height, std::vector<Cell>(this->width));
    std::cout << this->width << ' ' << this->height << '\n';
    std::cout << this->player_x << ' ' << this->player_y << '\n';
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            ev = nullptr;
            cl = nullptr;
            if ((x == 0 || x == (this->width - 1)) && y != 0 && y != (this->height - 1)) {
                cl = new WallVertType;
            } else if (y == 0 || y == (this->height - 1)) {
                cl = new WallHorType;
            } else {
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist(1, 50);
                switch (dist(rng)) {
                    case 1:
                        cl = new EnemyType;
                        ev = new Enemy;
                        break;
                    case 2:
                        cl = new CoinType;
                        ev = new GetCoin;
                        break;
                    case 3:
                        cl = new HealType;
                        ev = new Heal;
                        break;
                    case 4:
                        cl = new StoneType;
                        break;
                    case 5:
                        cl = new CollapseType;
                        ev = new Collapse;
                        break;
                    case 6:
                        cl = new IncreaseType;
                        ev = new Increase;
                        break;
                    case 7:
                        cl = new DecreaseType;
                        ev = new Decrease;
                        break;
                    default:
                        cl = new EmptyType;
                        break;
                }
            }
            if (dynamic_cast<PlayerEvent *>(ev))
                ev = dynamic_cast<PlayerEvent *>(ev);
            else if (dynamic_cast<FieldEvent *>(ev))
                ev = dynamic_cast<FieldEvent *>(ev);
            this->field.at(y).at(x) = Cell(cl, ev);
        }
    }
    cl = new PlayerType;
    this->field.at(this->player_y).at(this->player_x) = Cell(cl);
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

bool Field::move_player(Player *player, int x, int y) {
    int new_x = get_new_x(x);
    int new_y = get_new_y(y);
    int prev_x = this->player_x;
    int prev_y = this->player_y;
    if (this->field[new_y][new_x].get_pass()) {
        this->player_x = new_x;
        this->player_y = new_y;
        Cell cl = this->field.at(new_y).at(new_x);
        auto *pl = dynamic_cast<PlayerEvent *> (cl.get_event());
        auto *fl = dynamic_cast<FieldEvent *> (cl.get_event());
        if (pl) {
            pl->execute(player);
        } else if (fl) {
            fl->execute(this);
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
    if (prev_x < this->width && prev_y < this->height){
        CellType *cl = new EmptyType;
        this->field[prev_y][prev_x].set_type(cl);
        this->field[prev_y][prev_x].set_event(nullptr);
        cl = new PlayerType;
        this->field[this->player_y][this->player_x].set_type(cl);
    }
}

Cell Field::get_cell(int x, int y) const {
    return this->field.at(y).at(x);
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
    if ((this->height + this->height_inc) > 10) {
        this->height += this->height_inc;
    } else {
        this->height = 10;
    }
    update_coords();
    this->height_inc = 0;
}

void Field::update_width() {
    if ((this->width + this->width_inc) > 10) {
        this->width += this->width_inc;
    } else {
        this->width = 10;
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



