#ifndef LABS_CONTROLLER_H
#define LABS_CONTROLLER_H

#include "../Background/FieldView.h"
#include "../Characters/PlayerView.h"
#include "GameStatus.h"

class Controller {
public:
    Controller();

    void set_field(int, int);
    void set_field_standard();
    void set_step(Player::STEP);

    Player* get_player();
    Field* get_field();
    GameStatus* get_game_status();

    void check_win_game();
    void check_end_game();
    void set_status_on();
    GameStatus::STATUS get_status() const;
private:
    Player          player;
    Field            field;
    FieldView   field_view;
    GameStatus game_status;
};


#endif