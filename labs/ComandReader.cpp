#include <iostream>
#include "ComandReader.h"

ComandReader::ComandReader(){
    ComandReader::readInput();
}

void ComandReader::readInput() {
    readField();
    readMove();
}

void ComandReader::readField() {
    std::cout << "Enter filed size: height and width (min 10)\n";
    std::cout << "Width: ";
    std::string inputData;

    std::cin >> inputData;
    setWidth(checkUIData(inputData));

    std::cout << "Height: ";
    std::cin >> inputData;
    setHeight(checkUIData(inputData));
}

void ComandReader::readMove() {
    std::cout << "Use W,A,S,D for move player\nFor exit press e\n";
    char c;

    std::cin >> c;
    this->move = c;
}

unsigned int ComandReader::getFieldWidth() const{
    return this->fieldWidth;
}


unsigned int ComandReader::getFieldHeight() const{
    return this->fieldHeight;
}

unsigned int ComandReader::getPlayerPositionX() const {
    return this->playerPositionX;
}

unsigned int ComandReader::getPlayerPositionY() const {
    return this->playerPositionY;
}

char ComandReader::getWay() const {
    return this->move;
}


void ComandReader::setWidth(unsigned int width) {
    this->fieldWidth = width;
}

void ComandReader::setHeight(unsigned int height) {
    this->fieldHeight = height;
}

unsigned int ComandReader::checkUIData(const std::string& input) {
    if (isNumber(input)){
        int value = std::stoi(input);
        return value;
    } else {
        std::cout << "Incorrect value!\nDefault value is used\n";
        return 10;
    }
}

bool ComandReader::isNumber(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


