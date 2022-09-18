#include "Field.h"


Field::Field(int width, int height)
    : width(width), height(height), player_location({0, 0}) {

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
        for(size_t j = 0; j != width; ++j)
            field.at(i).push_back(other.field.at(i).at(j));
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

Field::Field(Field&& other) noexcept {
    this->swap(other);
}

Field& Field::operator=(Field&& other) noexcept {
    if (this != &other)
        this->swap(other);
    return *this;
}

std::vector<std::vector<Cell>> Field::get_field() const  {
    return field;
}

void Field::make_field() {
    field.at(0).at(0).set_obj(Cell::PLAYER);
    field.at(0).at(0).set_player_location(true);
    for(size_t i = 0; i != height; ++i) {
        size_t val = i == 0 ? 1 : 0;
        for(size_t j = val; j != width; ++j) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);

            switch(dist(rng)) {
                case 1:
                    field.at(i).at(j).set_obj(Cell::BOX);
                    break;
                case 2:
                    field.at(i).at(j).set_obj(Cell::HEAL);
                    break;
                case 3:
                    field.at(i).at(j).set_obj(Cell::ENEMY);
                    break;
                case 4:
                    field.at(i).at(j).set_obj(Cell::BARRIER);
                    break;
                default:
                    break;
            }
        }
    }
}

void Field::change_player_pos(Player::STEP s) {
    field.at(player_location.second).at(player_location.first).set_obj(Cell::STANDARD);
    field.at(player_location.second).at(player_location.first).set_player_location(false);

    switch(s) {
        case Player::UP:
            player_location.second--;
            break;
        case Player::DOWN:
            player_location.second++;
            break;
        case Player::LEFT:
            player_location.first--;
            break;
        case Player::RIGHT:
            player_location.first++;
            break;
    }

    player_location.first = player_location.first % width;
    player_location.second = player_location.second % height;

    if (player_location.first < 0) player_location.first += width;
    if (player_location.second < 0) player_location.second += height;

    field.at(player_location.second).at(player_location.first).set_obj(Cell::PLAYER);
    field.at(player_location.second).at(player_location.first).set_player_location(true);
}

int Field::get_height() const {
    return height;
}

int Field::get_width() const {
    return width;
}
