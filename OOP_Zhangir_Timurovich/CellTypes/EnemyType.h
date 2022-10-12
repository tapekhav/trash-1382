#pragma once

#include "CellType.h"


class EnemyType : public CellType {
public:
    EnemyType();

    ~EnemyType() override = default;

    void execute() override {};

    bool get_pass() override;

//    Event *get_event() override;

private:
    bool pass;
//    Event *event;
};