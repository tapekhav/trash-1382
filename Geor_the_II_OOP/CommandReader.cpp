#include "CommandReader.h"
Direction CommandReader::get_direction(){
    char d;
    std::cin >> d;
    switch(d){
        case 'w':
            return up;
        case 'e':
            return up_right;
        case 'd':
            return right;
        case 'x':
            return down_right;
        case 's':
            return down;
        case 'z':
            return down_left;
        case 'a':
            return left;
        case 'q':
            return up_left;
        default:
            std::cout << "Incorrect. Use qweasdzx to move.\n";
            return this->get_direction();
    }
}