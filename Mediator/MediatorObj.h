#ifndef MEDIATOR_OBJ_H
#define MEDIATOR_OBJ_H

#include "../Field/Field.h"

class MediatorObj;

class Mediator{
public:
    virtual void ShortCommandNotify(MediatorObj* obj, char Command) = 0;
    virtual void FieldSizeNotify(MediatorObj* obj, std::pair<int, int> StartField) = 0;
    virtual void LargeCommandNotify(MediatorObj* obj, std::string Command) = 0;
};

class MediatorObj{
protected:
    Mediator* mediator;
public:
    MediatorObj(Mediator* med = nullptr);
    void setMediator(Mediator* med);
    virtual ~MediatorObj() {}
};

#endif
