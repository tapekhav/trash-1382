#ifndef SURVIVAL_COMMANDREADER_H
#define SURVIVAL_COMMANDREADER_H

#include "Processing/Handle.h"
#include "Logging/Subject.h"
#include "Logging/Messages/CharMessage.h"
#include "Logging/Messages/IntIntMessage.h"
#include "Logging/Messages/ErrorDecorator.h"

#include <iostream>
#include <string>

class CommandReader : public Handle, public Subject {
public:
    void Start();
    void Help(bool type) const;

    void CreateMessage(int val1, int val2);

    void Read();
    void ReadWidthAndHeight();
    void GoodBye() const;

    void IncorrectInput();
    
    void VictoryMsg() const;
    void DefeatMsg() const;

private:

    char mApproval;
    std::pair<int, int> mSize;
};

#endif //SURVIVAL_COMMANDREADER_H