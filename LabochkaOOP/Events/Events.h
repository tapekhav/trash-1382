//
// Created by corvussharp on 11.10.22.
//

#ifndef LABOCHKAOOP_EVENTS_H
#define LABOCHKAOOP_EVENTS_H
#include "../Logs/Subject.h"
class Event: public Subject{
public:
    virtual void doing(void*) = 0;

};


#endif //LABOCHKAOOP_EVENTS_H
