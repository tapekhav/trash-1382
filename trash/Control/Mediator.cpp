#include "Mediator.h"

Mediator::Mediator()  {}

Mediator::~Mediator() {
    delete logging;
}

void Mediator::start() {
    auto vec = input.read_loggers();
    logging = new GameLog;
    init_logs(vec);
    input.read_char();

    if (input.get_char() != 'y') {
        input.read_size();
        game.set_field(input.get_width(), input.get_height());
    } else {
        game.set_field_standard();
    }

    while(input.get_step() != Player::EXIT && game.get_status() == GameStatus::ON) {
        input.read_step();
        game.set_step(input.get_step());

        game.check_win_game();
        game.check_end_game();
    }

    for (auto elem : vec)
        delete elem;
}

void Mediator::init_logs(std::vector<Logger*>& loggers) {
    int flag = 0;
    std::cout << "Хотите ли вы отслеживать изменения в игре? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    if (input.read_choice() == 'y') {
        logging->add_subject(game.get_player());
        logging->add_subject(game.get_field());
        logging->add_level("Game");
        flag = 1;
    }

    std::cout << "Хотите ли вы отслеживать статус игры? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    if (input.read_choice() == 'y') {
        logging->add_subject(game.get_game_status());
        logging->add_level("Status");
    }

    std::cout << "Хотите ли вы отслеживать ошибки? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    if (input.read_choice() == 'y') {
        if (flag == 0) logging->add_subject(game.get_field());
        logging->add_subject(&input);
        logging->add_level("Error");
    }

    logging->set_loggers(loggers);
}
