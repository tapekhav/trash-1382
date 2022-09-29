#include <valarray>
#include "Field.h"
#include "TrapEventJoker.h"
#include "TrapEventBanana.h"
#include "CellWall.h"
#include "CellGrass.h"
#include "CellPlayer.h"


Field::Field(unsigned int width,
             unsigned int height,
             unsigned int playerPositionX,
             unsigned int playerPositionY):
        height(height),
        width(width),
        playerPosition({playerPositionX, playerPositionY}){

    setField();
};


Field::Field(const Field& fieldObj):
    height(fieldObj.height),
    width(fieldObj.width),
    playerPosition(fieldObj.playerPosition){
    field = fieldObj.field; //копирование вектора
};

void Field::swap(Field &fieldObj){
    std::swap(height, fieldObj.height);
    std::swap(width, fieldObj.width);
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

    for(int h = 0; h < height; ++h){
        field.emplace_back();
        for(int w = 0; w < width; ++w){
            if (10 <= h + w and h + w <= 11){
                CellWall* cellwall = new CellWall();
                field.at(h).push_back(cellwall);
            }else {
                CellGrass* cellGrass = new CellGrass();
                field.at(h).push_back(cellGrass);
            }
            if (h+w == 3){
                auto* trapEvent = new TrapEventJoker();
                field.at(h).at(w)->setEvent(trapEvent);
            }
            if (h == height - 3){
                auto* trapEvent = new TrapEventBanana();
                field.at(h).at(w)->setEvent(trapEvent);
            }
            CellPlayer* cellPlayer = new CellPlayer();
            if (h == playerPosition.second and w == playerPosition.first) field.at(h).at(w) = cellPlayer;
        }
    }
};

unsigned int Field::getWidth() const{
    return width;
};

unsigned int Field::getHeight() const{
    return height;
};

const Cell& Field::getCell(unsigned int height, unsigned int width) const{
    return *field.at(height).at(width);
}

void Field::movePlayer(Player::STEP step) {

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

    newPosition.first%=int(width);
    if(newPosition.first < 0) newPosition.first += int(width);

    newPosition.second%=int(height);
    if(newPosition.second < 0) newPosition.second += int(height);


    if (field.at(newPosition.second).at(newPosition.first)->isPassable()){
        auto* cellGrass = new CellGrass();
        auto* cellPlayer = new CellPlayer();

        field.at(playerPosition.second).at(playerPosition.first)->~Cell();
        field.at(playerPosition.second).at(playerPosition.first) = cellGrass;

        field.at(newPosition.second).at(newPosition.first)->callEvent();
        field.at(newPosition.second).at(newPosition.first)->~Cell();
        field.at(newPosition.second).at(newPosition.first) = cellPlayer;

        playerPosition = newPosition;
    }
}