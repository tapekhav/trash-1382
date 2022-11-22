#include "Controller.h"


Controller::Controller() : field_view(nullptr), game_status(GameStatus()), context() {}

void Controller::set_field_view() {
    field_view = FieldView(context.get_field());
    field_view.update();
}

void Controller::set_field(int width, int height) {
    context.set_field_size(width, height);
    set_field_view();
}

void Controller::set_field_standard() {
    context.set_field_size();
    set_field_view();
}

void Controller::set_step(Player::STEP step) {
    context.get_field()->change_player_location(step);
    if (step != Player::EXIT) {
        field_view.update();
    }
}

Player *Controller::get_player() {
    return context.get_field()->get_player();
}

Field *Controller::get_field() {
    return context.get_field();
}

GameStatus *Controller::get_game_status() {
    return &game_status;
}

void Controller::check_end_game() {
    if (get_player()->get_health() <= 0)
        game_status.set_status_off(GameStatus::LOSE);
}

void Controller::check_win_game() {
    if (get_player()->get_keys() == 2)
        game_status.set_status_off(GameStatus::WIN);
}

GameStatus::STATUS Controller::get_status() const {
    return game_status.get_status();
}

void Controller::set_status_on() {
    game_status.set_status_on();
}
