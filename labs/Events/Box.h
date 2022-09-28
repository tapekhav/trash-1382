#ifndef LABS_BOX_H
#define LABS_BOX_H

#include "Event.h"

class Box: public Event {
public:
    void execute(Player& player) override;
    ~Box() override = default;
};


#endif //LABS_BOX_H
