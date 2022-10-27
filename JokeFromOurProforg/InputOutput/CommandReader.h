#ifndef SURVIVAL_COMMANDREADER_H
#define SURVIVAL_COMMANDREADER_H

#include "Processing/Handle.h"

#include <iostream>
#include <string>

class CommandReader : public Handle {
public:
    void Start();
    void Help(bool type) const;

    void Read();
    void ReadWidthAndHeight();
    void GoodBye() const;

    void IncorrectInput();
    
    void VictoryMsg() const;
    void DefeatMsg() const;

private:
    void CreateMessage(EnumClass::Log type, char* value);
    void CreateMessage(EnumClass::Log type, int* pos1, int* pos2);
    char mApproval;
    std::pair<int, int> mSize;
};

#endif //SURVIVAL_COMMANDREADER_H