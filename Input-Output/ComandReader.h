#ifndef COMAND_READER_H
#define COMAND_READER_H

#include "../Mediator/MediatorObj.h"
#include "../Field/Field.h"
#include "FieldView.h"
#include <limits>

class ComandReader : public MediatorObj{
private:
    char MoveSymbol;
    std::pair<int,int> FieldSize;
public:
    ComandReader(Mediator* med = nullptr);

    void Read();

    void ReadStartField();
    
    void setMediator(Mediator* med);
};

#endif