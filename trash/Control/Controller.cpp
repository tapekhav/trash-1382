#include "Controller.h"
#include "Field/FieldGenerator.h"
#include "Rules/RuleSpawnEventField.h"
#include "Rules/RuleSpawnEventPlayer.h"
#include "Rules/RuleSpawnKeys.h"
#include "Rules/RuleSpawnTrap.h"
#include "Rules/RuleSpawnWalls.h"
#include "Rules/RuleSpawnPlayer.h"


Controller::Controller() : field_view(nullptr), game_status(GameStatus()) {
    FieldGenerator<RuleSpawnKeys<22>,
                   RuleSpawnPlayer<5, 5>,
                   RuleSpawnEventField<SetWalls, 4>,
                   RuleSpawnWalls<11>,
                   RuleSpawnTrap<1488, 228, 1>,
                   RuleSpawnEventPlayer<Box, 1337>> gen;
    field = gen.fill(10, 10);
    field_view = FieldView(field);
}

void Controller::set_field(int width, int height) {
    field_view = FieldView(field);
    field_view.update();
}

void Controller::set_field_standard() {
    field_view.update();
}

void Controller::set_step(Player::STEP step) {
    field->change_player_location(step);
    if (step != Player::EXIT) {
        field_view.update();
    }
}

Player *Controller::get_player() {
    return field->get_player();
}

Field *Controller::get_field() {
    return field;
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
