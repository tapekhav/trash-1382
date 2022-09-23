#include <random>
#include "Field.h"
#include "TrapEvent.h"


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
    playerPosition(fieldObj.playerPosition),
    field(fieldObj.field){};

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
    field.resize(height);
    for(int h = 0; h < height; ++h){
        field.at(h).resize(width);
        for(int w = 0; w < width; ++w){
            if (10 <= h + w and h + w <= 11){
                field.at(h).at(w) = Cell(false, false);
            }else {
                field.at(h).at(w) = Cell(true, false);
            }
            if (h == playerPosition.second and w == playerPosition.first) field.at(h).at(w).setStepped();
        }
    }
};

unsigned int Field::getWidth() const{
    return this->width;
};

unsigned int Field::getHeight() const{
    return this->height;
};

const Cell& Field::getCell(unsigned int h, unsigned int w) const{
    return field.at(h).at(w).getCell();
};

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



    if (field.at(newPosition.second).at(newPosition.first).isPassable()){
        field.at(playerPosition.second).at(playerPosition.first).setUnstepped();
        field.at(newPosition.second).at(newPosition.first).setStepped();
        playerPosition = newPosition;
    }
};