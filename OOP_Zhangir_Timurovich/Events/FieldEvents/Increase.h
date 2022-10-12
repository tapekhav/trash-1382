#pragma once

#include "FieldEvent.h"

class Increase : public FieldEvent {
public:
    Increase() = default;

    ~Increase() override = default;

    bool execute(void *obj) override;
};
