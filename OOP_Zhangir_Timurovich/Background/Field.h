#pragma once

#include "Cell.h"
#include "../Logging/Subject.h"


class Field : public Subject {
public:
    explicit Field(LogOutInfo *info = nullptr, int width = 10, int
    height = 10);

    Field(Field &&other);

    Field(const Field &other);

    ~Field() = default;

    void create_field(Player *game_player);

    [[nodiscard]] std::vector<int> get_size() const;


    Field &operator=(const Field &other);

    Field &operator=(Field &&other);

    bool move_player(Player *player, int x, int y);

    [[nodiscard]] int get_player_x() const;

    [[nodiscard]] int get_player_y() const;

    Cell &get_cell(int x, int y);

    void add_width(int width);

    void add_height(int height);

    void set_cell(int x, int y, Cell cell);

    int get_width_inc() const;

    int get_height_inc() const;

    int get_width() const;

    int get_height() const;

    void set_player_loc(int x, int y);



private:
    int width{};
    int height{};
    int player_x{};
    int player_y{};
    int width_inc{};
    int height_inc{};
    std::vector<std::vector<Cell>> field;
    LogOutInfo *info;

    void update_events(Player *game_player);

    void swap(Field &other);

    void update_height();

    void update_width();

    [[nodiscard]] int get_new_x(int x) const;

    [[nodiscard]] int get_new_y(int y) const;

    void update_player(int prev_x, int prev_y);

    void update_coords();
};
