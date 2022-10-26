//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_FILEOUTPUT_H
#define LABOCHKAOOP_FILEOUTPUT_H
#include "fstream"
#include "Output.h"
class FileOutput: public Output{
public:
    FileOutput(std::string filename);

    ~FileOutput();

    Output &operator<<(std::string message) override;
private:
    std::ofstream file;
};


#endif //LABOCHKAOOP_FILEOUTPUT_H
