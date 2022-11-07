#pragma once

#include "../Characters/Player.h"
#include "../Characters/PlayerView.h"
#include "../Background/Field.h"
#include "../Background/FieldView.h"
#include "ConsoleReader.h"
#include "../Events/EventBuilder.h"
#include "../Info/Structs.h"
#include "../Info/LogOutInfo.h"
#include "../Logging/Subject.h"


class Controller : public Subject {
public:
    explicit Controller(LogOutInfo *info = nullptr, int width = 10, int height = 10, int
    health = 100, int armour = 100, int damage = 10);

    void show_field();

    bool move_player(MOVES move);

    void create_field();

    LogOutInfo* get_info();

    ~Controller() = default;


private:
    Player *player;
    FieldView field_view{};
    Field *field{};
    PlayerView player_view{};
    LogOutInfo *log_out_info;
};

