#pragma once

#include "Cell.h"
#include "../CellTypes/CellType.h"
#include "../CellTypes/CoinType.h"
#include "../CellTypes/CollapseType.h"
#include "../CellTypes/DecreaseType.h"
#include "../CellTypes/EmptyType.h"
#include "../CellTypes/EnemyType.h"
#include "../CellTypes/HealType.h"
#include "../CellTypes/IncreaseType.h"
#include "../CellTypes/PlayerType.h"
#include "../CellTypes/StoneType.h"
#include "../CellTypes/WallHorType.h"
#include "../CellTypes/WallVertType.h"

class CellView {
public:
    explicit CellView(Cell c);
    char get_view() const;
private:
    char view;
};

