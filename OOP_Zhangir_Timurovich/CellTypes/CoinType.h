#pragma once

#include "CellType.h"


class CoinType : public CellType {
public:
    CoinType();

    ~CoinType() override = default;

    void execute() override {};

    bool get_pass() override;

//    Event *get_event();

private:
    bool pass;
//    Event *event;
};
