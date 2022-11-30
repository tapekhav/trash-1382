#pragma once

#include "../Characters/Player.h"
#include "../Events/Event.h"
#include "../Logging/Subject.h"

class Cell{
public:

    explicit Cell(Event *event = nullptr);

    void set_player(bool arg);


    [[nodiscard]] bool get_pass() const;

    [[nodiscard]] Event *get_event() const;

    void set_pass(bool pass);

    [[nodiscard]] bool check_player() const;

    void set_event(Event *new_event);

    Cell(Cell &&other)

    noexcept;

    Cell &operator=(Cell &&other)

    noexcept;

    Cell(const Cell &other);

    Cell &operator=(const Cell &other);

    ~Cell() = default;

private:
    bool player_loc{};
    Event *event{};
    bool pass{};
    void swap(Cell &other);

};


