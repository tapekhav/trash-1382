#pragma once

#include "CellType.h"

class HealType : public CellType {
public:

    HealType();

    ~HealType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass;
};
