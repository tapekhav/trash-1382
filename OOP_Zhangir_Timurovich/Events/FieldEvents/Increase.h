#pragma once

#include "FieldEvent.h"

class Increase : public FieldEvent {
public:
    explicit Increase(Field* field, Player* player);

    ~Increase() override = default;

    bool execute(LogOutInfo* info) override;
};
