#include "Mediator.h"

Mediator::Mediator() {
    error_log = new ErrorLog(&input);
    status_log = new StatusLog(game.get_game_status());
    player_log = new GameLog(game.get_player());
    field_log = new GameLog(game.get_field());
}

Mediator::~Mediator() {
    delete error_log;
    delete player_log;
    delete field_log;
    delete status_log;
}

void Mediator::start() {
    input.read_char();

    if (input.get_char() != 'y') {
        input.read_size();
        game.set_field(input.get_width(), input.get_height());
    } else {
        game.set_field_standard();
    }

    auto vec = input.read_loggers();
    attach_loggers(vec);
    while(input.get_step() != Player::EXIT && game.get_status() == GameStatus::ON) {
        input.read_step();
        game.set_step(input.get_step());

        game.check_win_game();
        game.check_end_game();
    }
}

void Mediator::attach_loggers(std::vector<Logger*>& loggers) {
    error_log->set_loggers(loggers);
    status_log->set_loggers(loggers);
    player_log->set_loggers(loggers);
    field_log->set_loggers(loggers);
}
