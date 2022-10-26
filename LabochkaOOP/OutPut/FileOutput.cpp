//
// Created by corvussharp on 26.10.22.
//

#include "FileOutput.h"

FileOutput::FileOutput(std::string filename) {
    file.open(filename);
}
FileOutput::~FileOutput(){
    file.close();
}
Output &FileOutput::operator<<(std::string message) {
    file<<message;
    return *this;
}
