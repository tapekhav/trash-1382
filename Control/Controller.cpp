#include "Controller.h"


Controller::Controller() : field(Field()), field_view(FieldView(&field)),
                           player(Player()), player_view(PlayerView(&player)) {}

void Controller::set_field(int width, int height) {
    field = Field(width, height);
    field.make_field();
}

void Controller::set_field_standard() {
    field = Field();
    field.make_field();
}

void Controller::set_step(Player::STEP step) {
    field.change_player_pos(player, step);
}

bool Controller::end_game() const {
    return player.get_health() <= 0;
}

bool Controller::win_game() const {
    return player.get_keys() == 2;
}
