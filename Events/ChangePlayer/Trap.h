#ifndef LABS_TRAP_H
#define LABS_TRAP_H

#include "EventPlayer.h"
#include <random>

class Trap : public EventPlayer {
public:
    void execute(Player& player) override;
    ~Trap() override = default;
};


#endif //LABS_TRAP_H
