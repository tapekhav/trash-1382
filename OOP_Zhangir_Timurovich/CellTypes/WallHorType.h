#pragma once

#include "CellType.h"

class WallHorType : public CellType {
public:
    WallHorType();

    ~WallHorType() override = default;

    void execute() override {};

    bool get_pass() override;


private:
    bool pass;
};

