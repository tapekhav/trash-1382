#pragma once

#include "CellType.h"


class DecreaseType : public CellType {
public:
    DecreaseType();

    ~DecreaseType() override = default;

    void execute() override {};

    bool get_pass() override;


private:
    bool pass;
};


