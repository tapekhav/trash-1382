#ifndef LAB2_EVENTPLAYERADDSHIELD_H
#define LAB2_EVENTPLAYERADDSHIELD_H


#include "EventPlayer.h"

class EventPlayerAddShield: public EventPlayer{
public:
    explicit EventPlayerAddShield(int value = 0);
    ~EventPlayerAddShield() override = default;
private:
    void changeSpecification(Player* player) override;
    int value;
};



#endif
