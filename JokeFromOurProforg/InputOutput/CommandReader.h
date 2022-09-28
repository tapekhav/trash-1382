#ifndef SURVIVAL_COMMANDREADER_H
#define SURVIVAL_COMMANDREADER_H

#include "Logging/Handle.h"

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

private:

    char mApproval;
    std::pair<int, int> mSize;
};

#endif //SURVIVAL_COMMANDREADER_H