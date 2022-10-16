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

Cell Field::get_cur_cell(int x, int y) const  {
    return field.at(y).at(x);
}

std::pair<int, int> Field::get_player_location() const {
    return player_location;
}

void Field::generate_keys() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> gen_height(1, height - 1);
    std::uniform_int_distribution<int> gen_width(0, width - 1);

    std::pair<int, int> pair1 = {gen_height(rng), gen_width(rng)};

    std::pair<int, int> pair2 = {gen_height(rng), gen_width(rng)};

    while (pair1 == pair2) {
        pair2.first = gen_height(rng);
        pair2.second = gen_width(rng);
    }

    field.at(pair1.first).at(pair1.second).set_event(new Key);
    field.at(pair2.first).at(pair2.second).set_event(new Key);
}

Cell Field::generate_cell() {
    Cell cell;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(1, 50);

    switch(dist(rng)) {
        case 1: {
            cell.set_pass(false);
            break;
        }
        case 2: {
            cell.set_event(new Heal);
            break;
        }
        case 3: {
            cell.set_event(new Box);
            break;
        }
        case 4:
            cell.set_event(new Trap);
            break;
        case 5: {
            cell.set_event(new NewLevel);
            break;
        }
        default:
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
                field.at(0).emplace_back();
            } else {
                field.at(i).push_back(generate_cell());
            }
        }
    }
    generate_keys();
    this->notify();
}


void Field::change_player_pos(Player &player, Player::STEP s) {
    auto tmp = player_location;

    field.at(player_location.second).at(player_location.first).set_event(nullptr);

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

    if (field.at(tmp.second).at(tmp.first).get_pass()) {
        player_location = tmp;
    }

    field.at(player_location.second).at(player_location.first).update(player, *this);

    if (s != Player::EXIT) {
        this->notify();
    }
}

int Field::get_height() const {
    return height;
}

int Field::get_width() const {
    return width;
}


void Field::clear_field() {
    for (size_t i = 0; i != height; ++i) {
        for (size_t j = 0; j != width; ++j) {
            field.at(i).at(j).set_event(nullptr);
            field.at(i).at(j).set_pass(true);
        }
    }
    field.clear();
}
