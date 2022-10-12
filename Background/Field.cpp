#include "Field.h"

Field::Field(int width, int height)
    : width(width), height(height) {
    make_field();
}

Field::~Field() {
    clear_field();
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

CellType* Field::get_cur_cell(int x, int y) const  {
    return field.at(y).at(x);
}

void Field::generate_keys() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution gen_height(1, height - 1);
    std::uniform_int_distribution gen_width(0, width - 1);

    std::pair<int, int> pair1 = {gen_height(rng), gen_width(rng)};

    std::pair<int, int> pair2 = {gen_height(rng), gen_width(rng)};

    while (pair1 == pair2)
        pair2 = {gen_height(rng), gen_width(rng)};

    delete field.at(pair1.first).at(pair1.second);
    delete field.at(pair2.first).at(pair2.second);

    field.at(pair1.first).at(pair1.second) = new CellKey;
    field.at(pair2.first).at(pair2.second) = new CellKey;
}

CellType *Field::generate_cell() {
    CellType* cell;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution dist(1, 50);

    switch(dist(rng)) {
        case 1: {
            cell = new CellWall;
            break;
        }
        case 2: {
            cell = new CellHeal;
            break;
        }
        case 3: {
            cell = new CellBox;
            break;
        }
        case 4:
            cell = new CellTrap;
            break;
        case 5: {
            cell = new CellNewLevel;
            break;
        }
        case 6: {
            cell = new CellKey;
            break;
        }
        default:
            cell = new CellStandard;
            break;
    }

    return cell;
}

void Field::make_field() {
    player_location = {0, 0};
    for(int i = 0; i != height; ++i) {
        field.emplace_back();
        for(int j = 0; j != width; ++j) {
            if (i == 0 && j == 0) {
                field.at(0).push_back(new CellStandard);
            } else {
                field.at(i).push_back(generate_cell());
            }
        }
    }
    generate_keys();
    this->Notify();
}

Event* Field::change_player_pos(Player::STEP s) {
    auto tmp = player_location;

    delete field.at(player_location.second).at(player_location.first);
    field.at(player_location.second).at(player_location.first) = new CellStandard;

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

    Event* ev = field.at(tmp.second).at(tmp.first)->get_event();

    if (dynamic_cast<CellWall*>(field.at(tmp.second).at(tmp.first)) == nullptr) {
        player_location = tmp;
    }


    if (s != Player::EXIT) {
        this->Notify();
    }

    return ev;
}

int Field::get_height() const {
    return height;
}

int Field::get_width() const {
    return width;
}

void Field::clear_field() {
    for (size_t i = 0; i != height; ++i) {
        for (size_t j = 0; j != width; ++j)
            delete field.at(i).at(j);
    }

    field.clear();
}

std::pair<int, int> Field::get_player_location() const {
    return player_location;
}
