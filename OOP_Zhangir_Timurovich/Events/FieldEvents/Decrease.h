#pragma once

#include "FieldEvent.h"

class Decrease : public FieldEvent {
public:
    Decrease() = default;

    ~Decrease() override = default;

    void execute(void *obj) override;
};



