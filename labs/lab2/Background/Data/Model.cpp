#include <iostream>
#include "Model.h"

Model::Model(std::pair<int, int> size){
    std::cout << "Constructor Model\n";
    field = Field(size);
    std::cout << "Finished Model constr\n";
}

void Model::createField(std::pair<int, int> size) {
    std::cout << "New Field " << size.first << " " << size.second << '\n';
    field = Field(size);
    std::cout << "After constructor " <<field.getFieldSize().first << '\t' << field.getFieldSize().second << '\n';
    this->notify();
}

Field* Model::getField() {
    std::cout << "In get Field " << field.getFieldSize().first << '\t' << field.getFieldSize().second << '\n';
    return &field;
}

void Model::movePlayerPosition(char c) {
    std::cout << "In move player " << field.getFieldSize().first << '\t' << field.getFieldSize().second << '\n';

    Player::STEP s;
    switch (c) {
        case 'w':
            s = Player::UP;
            break;
        case 's':
            s = Player::DOWN;
            break;
        case 'a':
            s = Player::LEFT;
            break;
        case 'd':
            s = Player::RIGHT;
            break;
        default:
            s = Player::NOTHING;
            break;
    }
    field.movePlayer(s, player);
    this->notify();
}