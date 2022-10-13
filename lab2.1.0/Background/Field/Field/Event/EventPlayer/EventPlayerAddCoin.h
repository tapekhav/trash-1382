#ifndef LAB2_EVENTPLAYERADDCOIN_H
#define LAB2_EVENTPLAYERADDCOIN_H


#include "EventPlayer.h"

class EventPlayerAddCoin: public EventPlayer{
public:
    EventPlayerAddCoin(int value = 10);
    ~EventPlayerAddCoin() = default;
private:
    void changeSpecification(Player* player) override;
    int value;
};


#endif
