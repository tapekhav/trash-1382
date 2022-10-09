#include <iostream>
#include "Model.h"

Model::Model(std::pair<int, int> size){
    player = std::make_shared<Player>(Player());
    std::cout << "Constructor Model\n";
    field = Field(size);
    std::cout << "Finished Model constr\n";
}

void Model::createField(std::pair<int, int> size, std::pair<int, int> playerPosition) {
    field = Field(size, playerPosition);
    this->notify();
}

const Field* Model::getField() {
    return &field;
}

void Model::movePlayerPosition(char c) {
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

std::pair<int, int> Model::getPlayerPosition() const {
    return field.getPlayerPosition();
}

bool Model::isEndGame() const {
    if ((player->getCoins() >= (field.getFieldSize().first/2)*10) || (player->getHealth() <= 0)) return true;
    return false;
}