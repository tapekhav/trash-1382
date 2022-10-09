#ifndef LAB2_EVENTPLAYERADDHEALTH_H
#define LAB2_EVENTPLAYERADDHEALTH_H


#include "EventPlayer.h"

class EventPlayerAddHealth: public EventPlayer{
public:
    explicit EventPlayerAddHealth(int value = 0);
    ~EventPlayerAddHealth() override = default;
    void callReaction(std::shared_ptr<Player> player) override;
private:
    void changeSpecification(std::shared_ptr<Player> player) override;
    int value = 10;
};


#endif
