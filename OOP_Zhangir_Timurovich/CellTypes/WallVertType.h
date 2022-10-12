#pragma once

#include "CellType.h"


class WallVertType : public CellType {
public:
    WallVertType();

    ~WallVertType() override = default;

    void execute() override {};

    bool get_pass() override;


private:
    bool pass;
};
