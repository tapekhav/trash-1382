//
// Created by roman on 26.10.2022.
//

#include "FileOut.h"

FileOut::FileOut(std::string name) {
    file.open(name, std::ios_base::out | std::ios_base::app);
};

FileOut::~FileOut() {
    file.close();
}

void FileOut::print(Message &message) {
    if (file.is_open())
        file << message;
};