#ifndef GAME_EVENTPLAYERDOWNSHIELD_H
#define GAME_EVENTPLAYERDOWNSHIELD_H


#include "../Event.h"
#include "IEventPlayer.h"
#

class EventPlayerDownShield: public IEventPlayer{
public:
    EventPlayerDownShield(int value = 0);
    ~EventPlayerDownShield() = default;
    void callReaction(std::shared_ptr<Player> player) override;
private:
    void changeSpecification(std::shared_ptr<Player> player) override;
    int value = 10;
};


#endif
