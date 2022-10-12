#pragma once

//#include "../Events/Event.h"
//#include "../Events/FieldEvents/Collapse.h"
//#include "../Events/FieldEvents/Decrease.h"
//#include "../Events/FieldEvents/Increase.h"
//#include "../Events/PlayerEvents/Enemy.h"
//#include "../Events/PlayerEvents/GetCoin.h"
//#include "../Events/PlayerEvents/Heal.h"

//class Heal;
//
//class GetCoin;
//
//class Enemy;
//
//class Increase;
//
//class Decrease;
//
//class Collapse;

class CellType {
public:
    CellType() = default;

    virtual ~CellType() = default;

    virtual void execute() = 0;

    virtual bool get_pass() = 0;

//    virtual Event *get_event() = 0;
};





























