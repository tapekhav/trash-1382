#ifndef LAB2_EVENTFIELDSPAWNCOINS_H
#define LAB2_EVENTFIELDSPAWNCOINS_H


#include "EventField.h"

class EventFieldSpawnCoins: public EventField{
public:
    EventFieldSpawnCoins() = default;
    ~EventFieldSpawnCoins() = default;
private:
    void changeField(Field* ) override;
};

#endif
