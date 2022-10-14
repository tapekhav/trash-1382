#ifndef LAB2_EVENTPLAYEROPENCHEST_H
#define LAB2_EVENTPLAYEROPENCHEST_H


#include "EventPlayer.h"

class EventPlayerOpenChest: public EventPlayer{
public:
    explicit EventPlayerOpenChest(int value);
    ~EventPlayerOpenChest() override = default;
private:
    void changeSpecification(Player* player) override;
    int value;
};



#endif
