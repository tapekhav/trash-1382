#ifndef LAB2_EVENTPLAYERADDSHIELD_H
#define LAB2_EVENTPLAYERADDSHIELD_H


#include "EventPlayer.h"

class EventPlayerAddShield: public EventPlayer{
public:
    explicit EventPlayerAddShield(int value = 0);
    ~EventPlayerAddShield() override = default;
    void callReaction(std::shared_ptr<Player> player) override;
private:
    void changeSpecification(std::shared_ptr<Player> player) override;
    int value = 10;
};



#endif
