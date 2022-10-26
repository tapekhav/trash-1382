#include "Controller.h"


Controller::Controller() : field(Field()), field_view(FieldView(&field)),
                           player(Player()), player_view(PlayerView(&player)), game_status(GameStatus()),
                           field_log(&field), player_log(&player) {
    this->status_log = new StatusLog(&game_status);
}

Controller::~Controller() {
    delete status_log;
}


void Controller::set_field(int width, int height) {
    field = Field(width, height);
    field.make_field(player);
    field_view = FieldView(&field);
    field_view.update();
}

void Controller::set_field_standard() {
    field.make_field(player);
    field_view.update();
}

void Controller::set_step(Player::STEP step) {
    field.change_player_location(player, step);
    field_view.update();
}

void Controller::check_end_game() {
    if (player.get_health() <= 0)
        game_status.set_status(GameStatus::LOSE);
}

void Controller::check_win_game() {
    if (player.get_keys() == 2)
        game_status.set_status(GameStatus::WIN);
}

GameStatus::STATUS Controller::get_status() const {
    return game_status.get_status();
}
