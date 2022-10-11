#ifndef LABS_KEY_H
#define LABS_KEY_H

#include "EventPlayer.h"
#include <random>

class Key: public EventPlayer {
public:
    void execute(Player& player) override;
    ~Key() override = default;
};


#endif //LABS_KEY_H
