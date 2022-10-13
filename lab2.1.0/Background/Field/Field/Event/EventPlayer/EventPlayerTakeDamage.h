#ifndef LAB2_EVENTPLAYERTAKEDAMAGE_H
#define LAB2_EVENTPLAYERTAKEDAMAGE_H

#include "EventPlayer.h"

class EventPlayerTakeDamage: public EventPlayer{
public:
    explicit EventPlayerTakeDamage(int value);
    ~EventPlayerTakeDamage() override = default;
private:
    void changeSpecification(Player* player) override;
    int value;
};


#endif
