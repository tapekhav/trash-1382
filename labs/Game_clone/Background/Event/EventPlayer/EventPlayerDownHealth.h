#ifndef GAME_EVENTPLAYERDOWNHEALTH_H
#define GAME_EVENTPLAYERDOWNHEALTH_H


#include "../Event.h"
#include "IEventPlayer.h"


class EventPlayerDownHealth: public IEventPlayer{
public:
    EventPlayerDownHealth(int value = 0);
    ~EventPlayerDownHealth() = default;
    void callReaction(std::shared_ptr<Player> player) override;
private:
    void changeSpecification(std::shared_ptr<Player> player) override;
    int value = 10;
};


#endif
