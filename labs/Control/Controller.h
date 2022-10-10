#ifndef LABS_CONTROLLER_H
#define LABS_CONTROLLER_H

#include "../Background/FieldView.h"
#include "../Characters/PlayerView.h"

class Controller {
public:
    Controller();

    void set_field(int width, int height);
    void set_field_standard();
    void set_step(Player::STEP step);

    bool end_game() const;
private:
    Player player;
    Field field;
    PlayerView player_view;
    FieldView field_view;
};


#endif