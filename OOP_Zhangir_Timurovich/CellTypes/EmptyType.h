#pragma once

#include "CellType.h"

class EmptyType : public CellType {
public:
    EmptyType();

    ~EmptyType() override = default;

    void execute() override {};

    bool get_pass() override;

//    Event *get_event();

private:
    bool pass;
//    Event * event;
};

