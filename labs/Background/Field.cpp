#include "Field.h"


Field::Field(int width, int height)
    : width(width), height(height), player_location({0, 0}), player() {
    for(size_t i = 0; i != height; ++i) {
        field.emplace_back();
        for(size_t j = 0; j != width; ++j) {
            field.at(i).emplace_back();
        }
    }
}


Field::Field(const Field &other)
    : width(other.width), height(other.height), player_location(other.player_location) {
    for(size_t i = 0; i != height; ++i) {
        field.emplace_back();
        for(size_t j = 0; j != width; ++j) {
            field.at(i).push_back(other.field.at(i).at(j));
        }
    }
}

void Field::swap(Field &other) {
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(field, other.field);
    std::swap(player_location, other.player_location);
}

Field& Field::operator=(const Field &other) {
    if (this != &other)
        Field(other).swap(*this);

    return *this;
}

Field::Field(Field&& other) {
    this->swap(other);
}

Field& Field::operator=(Field&& other) {
    if (this != &other)
        this->swap(other);
    return *this;
}

Cell Field::get_cur_cell(int x, int y) const  {
    return field.at(y).at(x);
}

void Field::generate_enemy() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution gen_height(1, height - 1);
    std::uniform_int_distribution gen_width(0, width - 1);

    auto* enemy = new Enemy;
    field.at(gen_height(rng)).at(gen_width(rng)).set_event(enemy);
    field.at(gen_height(rng)).at(gen_width(rng)).set_event(enemy);
}

void Field::make_field() {
    field.at(0).at(0).set_player_in(true);
    for(size_t i = 0; i != height; ++i) {
        size_t val = i == 0 ? 1 : 0;
        for(size_t j = val; j != width; ++j) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution dist(1,50);

            switch(dist(rng)) {
                case 1: {
                    Box *box = new Box;
                    field.at(i).at(j).set_event(box);
                    break;
                }
                case 2: {
                    Heal *heal = new Heal;
                    field.at(i).at(j).set_event(heal);
                    break;
                }
                case 3:
                    field.at(i).at(j).set_passability(false);
                    break;
                default:
                    break;
            }
        }
    }
    generate_enemy();
}



void Field::change_player_pos(Player::STEP s) {
    auto tmp = player_location;
    field.at(player_location.second).at(player_location.first).set_player_in(false);

    switch(s) {
        case Player::UP:
            tmp.second--;
            break;
        case Player::DOWN:
            tmp.second++;
            break;
        case Player::LEFT:
            tmp.first--;
            break;
        case Player::RIGHT:
            tmp.first++;
            break;
        default:
            break;
    }

    tmp.first %= width;
    tmp.second %= height;

    if (tmp.first < 0) tmp.first += width;
    if (tmp.second < 0) tmp.second += height;

    if (field.at(tmp.second).at(tmp.first).get_passability()) {
        player_location = tmp;
    }

    field.at(player_location.second).at(player_location.first).set_player_in(true);
    field.at(player_location.second).at(player_location.first).update(player);
}

int Field::get_height() const {
    return height;
}

int Field::get_width() const {
    return width;
}
