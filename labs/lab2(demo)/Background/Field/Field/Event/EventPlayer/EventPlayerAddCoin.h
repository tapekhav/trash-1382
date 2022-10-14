#ifndef LAB2_EVENTPLAYERADDCOIN_H
#define LAB2_EVENTPLAYERADDCOIN_H


#include "EventPlayer.h"

class EventPlayerAddCoin: public EventPlayer{
public:
    explicit EventPlayerAddCoin(int value = 10);
    ~EventPlayerAddCoin() override = default;
private:
    void changeSpecification(Player* player) override;
    int value;
};


#endif
