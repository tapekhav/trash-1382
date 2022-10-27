#include "Controller.h"
#include "CommandReader.h"
#include "../Logging/logs/GameObserver.h"
#include "../Logging/logs/ErrorsObserver.h"


Controller::Controller(LogOutInfo *info, int width, int height, int health, int armour, int
damage) {
    this->player = new Player(info, health, armour, damage);
    this->field = new Field(info, width, height);
    this->field_view = FieldView(this->field);
    this->player_view = PlayerView(this->player);
    this->log_out_info = info;
    new GameObserver(this->player);
    new GameObserver(this->field);
    new ErrorsObserver(this->field);
}

void Controller::show_field() {
    this->field_view.show_field();
    this->player_view.show_chars();
}

void Controller::create_field() {
    Message message(STATUS, "Game started", log_out_info);
    notify(message);
    this->field->create_field(player);
}


bool Controller::move_player(CommandReader::MOVES move) {
    int x = 0;
    int y = 0;
    switch (move) {
        case CommandReader::MOVES::LEFT:
            x -= 1;
            break;
        case CommandReader::MOVES::RIGHT:
            x += 1;
            break;
        case CommandReader::MOVES::UP:
            y -= 1;
            break;
        case CommandReader::MOVES::DOWN:
            y += 1;
            break;
        case CommandReader::MOVES::NOWHERE:
            return true;
    }

    bool res = field->move_player(player, x, y);
    if (!res) {
        Message message(STATUS, "Game over", log_out_info);
        notify(message);
    }
    return res;
}

LogOutInfo *Controller::get_info() {
    return this->log_out_info;
}


