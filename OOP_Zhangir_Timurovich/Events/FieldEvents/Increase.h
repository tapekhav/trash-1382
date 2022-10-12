#pragma once

#include "FieldEvent.h"

class Increase : public FieldEvent {
public:
    Increase() = default;

    ~Increase() override = default;

    void execute(void *obj) override;
};
