#pragma once

#include "../Characters/Player.h"
#include "../Events/Event.h"
#include "../CellTypes/CellType.h"

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


