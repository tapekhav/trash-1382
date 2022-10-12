#pragma once

#include "FieldEvent.h"

class Collapse : public FieldEvent {
public:
    Collapse() = default;

    ~Collapse() override = default;

    bool execute(void *obj) override;
};



