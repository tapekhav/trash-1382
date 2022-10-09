#ifndef GAME_EVENTPLAYERADDHEALTH_H
#define GAME_EVENTPLAYERADDHEALTH_H


#include "../Event.h"
#include "IEventPlayer.h"


class EventPlayerAddHealth: public IEventPlayer{
public:
    EventPlayerAddHealth(int value = 0);
    ~EventPlayerAddHealth() = default;
    void callReaction(std::shared_ptr<Player> player) override;
private:
    void changeSpecification(std::shared_ptr<Player> player) override;
    int value = 10;

};


#endif
