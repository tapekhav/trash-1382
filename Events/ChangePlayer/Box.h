#ifndef LABS_BOX_H
#define LABS_BOX_H

#include "EventPlayer.h"

class Box : public EventPlayer {
public:
    void execute(Player& player) override;
    ~Box() override = default;
};


#endif //LABS_BOX_H
