#pragma once

#include "../Characters/Player.h"
#include "../Events/Event.h"
#include "../CellTypes/CellType.h"

class Cell {
public:

    explicit Cell();

    CellType* get_type();

    void set_type(CellType* cell_type);

    [[nodiscard]] bool check_player() const;

    void set_event(Event *new_event);
    Cell(Cell&& other) noexcept ;
    Cell& operator=(Cell&& other) noexcept ;
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    ~Cell() = default;

private:
    bool player_loc{};
    Event *event{};
    CellType* type{};

    void set_player();
    void swap(Cell &other);

};


