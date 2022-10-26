//
// Created by roman on 26.10.2022.
//

#include "ConsoleOut.h"


Output& ConsoleOut::operator<<(std::string message){
    std::cout<<message<<'\n';
    return *this;
};
