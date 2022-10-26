//
// Created by roman on 26.10.2022.
//

#include "FileOut.h"

FileOut::FileOut(std::string filename){
    file.open(filename);
};

FileOut::~FileOut(){
    file.close();
}

Output& FileOut::operator <<(std::string message){
    file<<message;
    return *this;
};