#ifndef LAB2_EVENTFIELDCRASHWALL_H
#define LAB2_EVENTFIELDCRASHWALL_H


#include "EventField.h"

class EventFieldCrashWall: public EventField{
public:
    EventFieldCrashWall() = default;
    ~EventFieldCrashWall() = default;
private:
    void changeField(Field* ) override;
};


#endif
