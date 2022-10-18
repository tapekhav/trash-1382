#pragma once

#include "../Background/Field.h"
#include "../Characters/Player.h"
#include "Event.h"
#include "FieldEvents/Collapse.h"
#include "FieldEvents/Increase.h"
#include "FieldEvents/Decrease.h"
#include "PlayerEvents/Enemy.h"
#include "PlayerEvents/Heal.h"
#include "PlayerEvents/GetCoin.h"
#include "GameRulesEvents/Win.h"
#include "GameRulesEvents/Lose.h"

class EventBuilder {
public:
    EventBuilder(Field *field, Player *player);

    void update_events();

    Event *create_HealEvent();

    Event *create_CoinEvent();

    Event *create_EnemyEvent();

    Event *create_IncreaseEvent();

    Event *create_DecreaseEvent();

    Event *create_CollapseEvent();

    Event *create_WinEvent();

    Event *create_LoseEvent();

private:
    Field *field;
    Player *player;
};
