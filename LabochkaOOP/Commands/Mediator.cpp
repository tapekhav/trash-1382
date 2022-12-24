//
// Created by corvussharp on 21.09.22.
//

#include "Mediator.h"
#include "../LOG/Logs/LogsStatus.h"

void Mediator::start() {
    input.set_output();
    input.set_level();

    Logger::getInstance().setLogOutInfo(LogOutInfo{input.get_outputs(), input.get_levels()});
    LogsStatus logsStatus((this->game));

    ControlConfig *cfg = new ControlFile("cfg.txt");
    cfg->read_config();
    cread.set_config(cfg);

    cread.field_choice();
    if (cread.get_sym() != 'X') {
        input.set_size();
        play.set_field(input.get_width(), input.get_height());
    } else {
        play.set_field_base();
    }
    while (cread.get_step() != CONTROL::EXIT) {
        play.print_stats();
        play.print_field();
        if (play.death_person()) {
            return;
        }
        if (play.win_game()) {
            return;
        }
        cread.read_step();
        play.set_step(cread.get_step());
    }
}
