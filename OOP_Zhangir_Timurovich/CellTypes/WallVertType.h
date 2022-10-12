#pragma once

#include "CellType.h"


class WallVertType : public CellType {
public:
    WallVertType();

    ~WallVertType() override = default;

    void execute() override {};

    bool get_pass() override;

//    Event *get_event() override;

private:
    bool pass;
//    Event *event;
};
