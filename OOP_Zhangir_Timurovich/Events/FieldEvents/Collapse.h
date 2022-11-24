#pragma once

#include "FieldEvent.h"

class Collapse : public FieldEvent {
public:
    explicit Collapse(Field *field, Player* player);


    ~Collapse() override = default;

    bool execute(LogOutInfo* info) override;

};



