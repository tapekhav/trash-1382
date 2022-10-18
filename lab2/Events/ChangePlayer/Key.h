#ifndef LABS_KEY_H
#define LABS_KEY_H

#include "EventPlayer.h"
#include <random>

class Key final : public EventPlayer {
public:
    explicit Key(Player* player);
    void execute() final;
};


#endif //LABS_KEY_H
