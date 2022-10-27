#pragma once

#include "FieldEvent.h"

class Decrease : public FieldEvent {
public:
    Decrease(Field *field, Player *player);

    ~Decrease() override = default;

    bool execute(LogOutInfo* info) override;
};



