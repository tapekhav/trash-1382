#include <iostream>
#include <utility>
#include "Field.h"
#include "Event/EventPlayer/EventPlayerAddHealth.h"
#include "Event/EventPlayer/EventPlayerAddCoin.h"
#include "Event/EventPlayer/EventPlayerAddShield.h"


Field::Field(std::pair<int, int> fieldSize, std::pair<int, int> playerPosition):
        fieldSize(fieldSize),
        playerPosition(playerPosition){

    setField();
};


Field::Field(const Field& fieldObj):
        fieldSize(fieldObj.fieldSize),
        playerPosition(fieldObj.playerPosition){
    for (int h = 0; h != fieldSize.second; ++h){
        field.emplace_back();
        for (int w = 0; w != fieldSize.first; ++w){
            field.at(h).push_back(fieldObj.field.at(h).at(w));
        }
    }
};

void Field::swap(Field &fieldObj){
    std::swap(fieldSize, fieldObj.fieldSize);
    std::swap(field, fieldObj.field);
    std::swap(playerPosition, fieldObj.playerPosition);
}

Field& Field::operator=(const Field& fieldObj){
    if(this != &fieldObj){
        Field(fieldObj).swap(*this);
    }
    return *this;
}

Field::Field(Field&& fieldObj){
    this->swap(fieldObj);
};

Field& Field::operator=(Field&& filedObj) {
    if (this != &filedObj)
        this->swap(filedObj);
    return *this;
}


void Field::setField(){
    std::cout << "Set field\n";
    for(int h = 0; h < fieldSize.second; ++h){
        field.emplace_back();
        for(int w = 0; w < fieldSize.first; ++w){
            if (10 <= h + w and h + w <= 11){
                auto cellWall = cellFactory.getCell("Wall");
                field.at(h).push_back(*cellWall);
            }else {
                auto cellGrass = cellFactory.getCell("Grass");
                field.at(h).push_back(*cellGrass);
            }
            if (h+w == 3){
                auto* addHealth = new EventPlayerAddHealth(10);
                field.at(h).at(w).setEvent(addHealth);
            }
            if (h == fieldSize.second - 3){
                auto* addCoin = new EventPlayerAddCoin(10);
                field.at(h).at(w).setEvent(addCoin);
            }
            if (w == fieldSize.first - 3){
                auto* addShield = new EventPlayerAddShield(10);
                field.at(h).at(w).setEvent(addShield);
            }
            if (h == playerPosition.second and w == playerPosition.first) field.at(h).at(w) = *cellFactory.getCell("Player");
        }
    }
    std::cout << "Field seted\n";
};

std::pair<int, int> Field::getFieldSize() const{
    return fieldSize;
};

const Cell& Field::getCell(int height, int width) const{
    return field.at(height).at(width).getCell();
}

void Field::movePlayer(Player::STEP step, std::shared_ptr<Player> player) {

    auto newPosition = playerPosition;
    switch (step) {
        case Player::UP:
            ++newPosition.second;
            break;
        case Player::DOWN:
            --newPosition.second;
            break;
        case Player::LEFT:
            --newPosition.first;
            break;
        case Player::RIGHT:
            ++newPosition.first;
            break;
        default:
            break;
    }

    newPosition.first%=int(fieldSize.first);
    if(newPosition.first < 0) newPosition.first += int(fieldSize.first);

    newPosition.second%=int(fieldSize.second);
    if(newPosition.second < 0) newPosition.second += int(fieldSize.second);


    if (field.at(newPosition.second).at(newPosition.first).isPassable()){
        field.at(newPosition.second).at(newPosition.first).callEvent(player);
        field.at(newPosition.second).at(newPosition.first).Cell::~Cell();
        field.at(newPosition.second).at(newPosition.first) = field.at(playerPosition.second).at(playerPosition.first);

        field.at(playerPosition.second).at(playerPosition.first).Cell::~Cell();
        field.at(playerPosition.second).at(playerPosition.first) = *cellFactory.getCell("Grass");

        playerPosition = newPosition;
    }
}

std::pair<int, int> Field::getPlayerPosition() const {
    return playerPosition;
}
