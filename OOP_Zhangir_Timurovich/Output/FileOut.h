//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_FILEOUT_H
#define MAIN_CPP_FILEOUT_H


#include "Output.h"
#include <fstream>
#include <string>

class FileOut : public Output {
public:
    FileOut(std::string name);

    ~FileOut();

    void print(Message &message) override;

private:
    std::ofstream file;
};


#endif //MAIN_CPP_FILEOUT_H
