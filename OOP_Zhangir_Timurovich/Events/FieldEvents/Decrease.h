#pragma once

#include "FieldEvent.h"

class Decrease : public FieldEvent {
public:
    Decrease() = default;

    ~Decrease() override = default;

    bool execute(void *obj) override;
};



