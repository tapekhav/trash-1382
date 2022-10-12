#pragma once

#include "../Characters/Player.h"
#include "../Events/Event.h"
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

class Cell {
public:

    explicit Cell(CellType *cell_type = new EmptyType, Event *event = nullptr);

    CellType *get_type();

    void set_type(CellType *cell_type);

    bool get_pass() const;

    Event *get_event() const;

    void set_pass(bool pass);

    [[nodiscard]] bool check_player() const;

    void set_event(Event *new_event);

    Cell(Cell &&other) noexcept;

    Cell &operator=(Cell &&other) noexcept;

    Cell(const Cell &other);

    Cell &operator=(const Cell &other);

    ~Cell() = default;

private:
    bool player_loc{};
    Event *event{};
    CellType *type{};
    bool pass{};


    void set_player();

    void swap(Cell &other);

};


