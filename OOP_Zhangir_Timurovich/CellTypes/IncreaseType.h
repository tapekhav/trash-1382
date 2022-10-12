#pragma once

#include "CellType.h"

class IncreaseType : public CellType {
public:
    IncreaseType();

    ~IncreaseType() override = default;

    void execute() override {};

    bool get_pass() override;


private:
    bool pass;
};



