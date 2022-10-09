#ifndef GAME_EVENTPLAYERADDSHIELD_H
#define GAME_EVENTPLAYERADDSHIELD_H


#include "../Event.h"
#include "IEventPlayer.h"


class EventPlayerAddShield: public IEventPlayer{
public:
    EventPlayerAddShield(int value = 0);
    ~EventPlayerAddShield() = default;
    void callReaction(std::shared_ptr<Player> player) override;
private:
    void changeSpecification(std::shared_ptr<Player> player) override;
    int value = 10;
};


#endif
