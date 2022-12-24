//
// Created by corvussharp on 28.10.22.
//

#ifndef LABOCHKAOOP_FILEOUT_H
#define LABOCHKAOOP_FILEOUT_H

#include <fstream>
#include "../Logging/Message.h"
#include "Output.h"

class FileOut : public Output {
public:
    FileOut(std::string name);

    ~FileOut();

    void print(Message &message) override;

private:
    std::ofstream file;
};


#endif //LABOCHKAOOP_FILEOUT_H
