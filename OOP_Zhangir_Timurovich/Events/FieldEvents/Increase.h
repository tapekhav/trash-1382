#pragma once

#include "FieldEvent.h"

class Increase : public FieldEvent {
public:
    Increase(Field* field, Player* player);

    ~Increase() override = default;

    bool execute() override;
};
