#include "Field.h"

Field::Field(unsigned int width,
             unsigned int height,
             unsigned int playerPositionX,
             unsigned int playerPositionY):
        height(height),
        width(width),
        playerPositionX(playerPositionX),
        playerPositionY(playerPositionY){

    setField();
};

void Field::setField(){
    field.resize(this->height);
    for(int h = 0; h < this->height; ++h){
        field.at(h).resize(this->width);
        for(int w = 0; w < this->width; ++w){
            if (h == 3 && w == 2){
                this->playerPositionX = 2;
                this->playerPositionY = 3;
                field.at(h).at(w) = Cell(true, true);
                continue;
            }
            if (h + w == 10){
                field.at(h).at(w) = Cell(false, false);
            }else {
                field.at(h).at(w) = Cell(true, false);
            }
        }
    }
};

unsigned int Field::getWidth() const{
    return this->width;
};

unsigned int Field::getHeight() const{
    return this->height;
};

Cell Field::getCell(int h, int w) const{
    return this->field.at(h).at(w);
}

void Field::setPlayerPosition(unsigned int playerPositionX, unsigned int playerPositionY) {
    //TODO проверить можно ил пройти и проверить на перенос в другое метос
    this->field.at(playerPositionY).at(playerPositionX).setUnstepped();
    this->playerPositionX = playerPositionX;
    this->playerPositionY = playerPositionY;
    this->field.at(this->playerPositionY).at(this->playerPositionX).setStepped();
}

unsigned int Field::getPlayerPositionX() const {
    return this->playerPositionX;
}

unsigned int Field::getPlayerPositionY() const {
    return this->playerPositionY;
};