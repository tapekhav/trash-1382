#ifndef LAB2_EVENTPLAYERADDCOIN_H
#define LAB2_EVENTPLAYERADDCOIN_H


#include "EventPlayer.h"

class EventPlayerAddCoin: public EventPlayer{
public:
    EventPlayerAddCoin(int value = 0);
    ~EventPlayerAddCoin() = default;
    void callReaction(std::shared_ptr<Player> player) override;
private:
    void changeSpecification(std::shared_ptr<Player> player) override;
    int value = 10;
};


#endif
