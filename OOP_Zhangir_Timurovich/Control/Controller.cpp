#include "Controller.h"
#include "CommandReader.h"
#include "../Logging/logs/GameObserver.h"
#include "../Logging/logs/ErrorsObserver.h"
#include "../Logging/logs/StatusObserver.h"

Controller::Controller(LogOutInfo* info, int width, int height, int health, int armour, int
damage) {
    this->player = new Player(health, armour, damage);
    this->field = new Field(width, height);
    this->field_view = FieldView(this->field);
    this->player_view = PlayerView(this->player);
    this->log_out_info = info;
    Observer* observer = new GameObserver(this->player);
    observer = new GameObserver(this->field);
}

void Controller::show_field() {
    this->field_view.show_field();
    this->player_view.show_chars();
}

void Controller::create_field() {
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
    return field->move_player(player, x, y);
}


