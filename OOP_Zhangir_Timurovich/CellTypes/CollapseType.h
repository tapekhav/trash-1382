#pragma once

#include "CellType.h"


class CollapseType : public CellType {
public:
    CollapseType();

    ~CollapseType() override = default;

    void execute() override {};

    bool get_pass() override;

private:
    bool pass ;
};



