#pragma once

#include "../Characters/Player.h"
#include "../Events/Event.h"

class Cell {
public:
    enum TYPE {
        coin,
        enemy,
        wall_vert,
        wall_hor,
        heal,
        empty,
        player,
        fix
    };

    explicit Cell(TYPE type = empty);

    TYPE get_obj();

    void set_obj(TYPE obj);

    [[nodiscard]] bool check_player() const;

    void set_event(Event *new_event);
    Cell(Cell&& other) noexcept ;
    Cell& operator=(Cell&& other) noexcept ;
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    ~Cell() = default;

private:
    TYPE obj;
    bool player_loc{};
    Event *event{};

    void set_player();
    void swap(Cell &other);

};


