#pragma once

#include "Cell.h"
#include "../CellTypes/CellType.h"


class Field {
public:
    explicit Field(int width = 10, int height = 10);

    Field(Field &&other) noexcept;

    Field(const Field &other);

    ~Field() = default;

    void create_field();

    [[nodiscard]] std::vector<int> get_size() const;

    Field &operator=(const Field &other);

    Field &operator=(Field &&other) noexcept;

    bool move_player(Player *player, int x, int y);

    [[nodiscard]] int get_player_x() const;

    [[nodiscard]] int get_player_y() const;

    Cell get_cell(int x, int y) const;

    void add_width(int width);

    void add_height(int height);

    int get_width_inc() const;

    int get_height_inc() const;

    int get_width() const;

    int get_height() const;

private:
    int width{};
    int height{};
    int player_x{};
    int player_y{};
    int width_inc{};
    int height_inc{};
    std::vector<std::vector<Cell>> field;

    void swap(Field &other);

    void update_height();

    void update_width();

    [[nodiscard]] int get_new_x(int x) const;

    [[nodiscard]] int get_new_y(int y) const;

    void update_player(int prev_x, int prev_y);

    void update_coords();

};
