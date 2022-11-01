#include "Controller.h"


Controller::Controller() : field(Field()), field_view(FieldView(&field)),
                           player(Player()), game_status(GameStatus()) {}


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
    if (step != Player::EXIT) {
        field_view.update();
    }
}

Player *Controller::get_player() {
    return &player;
}

Field *Controller::get_field() {
    return &field;
}

GameStatus *Controller::get_game_status() {
    return &game_status;
}

void Controller::check_end_game() {
    if (player.get_health() <= 0)
        game_status.set_status_off(GameStatus::LOSE);
}

void Controller::check_win_game() {
    if (player.get_keys() == 2)
        game_status.set_status_off(GameStatus::WIN);
}

GameStatus::STATUS Controller::get_status() const {
    return game_status.get_status();
}

void Controller::set_status_on() {
    game_status.set_status_on();
}
