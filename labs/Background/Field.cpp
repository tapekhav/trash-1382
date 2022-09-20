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
    : width(other.width), height(other.height), player_location(other.player_location), field(other.field) {}

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

bool Field::check_cell(Cell cell) const {
    if(cell.get_obj() == Cell::BARRIER)
        return false;
    return true;
}

void Field::change_player_pos(Player::STEP s) {
    auto tmp = player_location;
    field.at(player_location.second).at(player_location.first).set_obj(Cell::STANDARD);

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

    tmp.first = tmp.first % width;
    tmp.second = tmp.second % height;

    if (tmp.first < 0) tmp.first += width;
    if (tmp.second < 0) tmp.second += height;

    if (check_cell(field.at(tmp.second).at(tmp.first))) {
        player_location = tmp;
    }

    field.at(player_location.second).at(player_location.first).set_obj(Cell::PLAYER);
}

int Field::get_height() const {
    return height;
}

int Field::get_width() const {
    return width;
}
