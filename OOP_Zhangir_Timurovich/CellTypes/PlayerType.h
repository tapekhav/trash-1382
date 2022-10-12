#pragma once

#include "CellType.h"

class PlayerType : public CellType {
public:
    PlayerType();

    ~PlayerType() override = default;

    void execute() override {};

    bool get_pass() override;


private:
    bool pass;
};


