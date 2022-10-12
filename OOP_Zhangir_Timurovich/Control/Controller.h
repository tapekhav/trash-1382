#pragma once

#include "../Characters/Player.h"
#include "../Characters/PlayerView.h"
#include "../Background/Field.h"
#include "../Background/FieldView.h"
#include "CommandReader.h"


class Controller {
public:
    explicit Controller(int width = 10, int height = 10, int health = 100, int
    armour = 100, int damage = 10);

    void show_field();

    bool move_player(CommandReader::MOVES move);

    void create_field();

    ~Controller() = default;


private:
    Player* player;
    FieldView field_view{};
    Field *field{};
    PlayerView player_view{};
};

