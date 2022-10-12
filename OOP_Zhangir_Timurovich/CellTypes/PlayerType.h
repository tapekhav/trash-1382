#pragma once

#include "CellType.h"

class PlayerType : public CellType {
public:
    PlayerType();

    ~PlayerType() override = default;

    void execute() override {};

    bool get_pass() override;

//    Event *get_event() override;

private:
    bool pass;
//    Event *event;
};


