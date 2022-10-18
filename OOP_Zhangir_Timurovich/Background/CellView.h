#pragma once

#include "Cell.h"
#include "../Events/Event.h"
#include "../Events/FieldEvents/Collapse.h"
#include "../Events/FieldEvents/Increase.h"
#include "../Events/FieldEvents/Decrease.h"
#include "../Events/PlayerEvents/Enemy.h"
#include "../Events/PlayerEvents/Heal.h"
#include "../Events/PlayerEvents/GetCoin.h"

class CellView {
public:
    explicit CellView(Cell c);
    char get_view() const;
private:
    char view;
};

