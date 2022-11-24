#include "Controller.h"
#include "ConsoleReader.h"
#include "../Logging/logs/GameObserver.h"
#include "../Logging/logs/ErrorsObserver.h"
#include "../Background/FieldGeneration/FieldGenerator.h"
#include "../Background/FieldGeneration/Rules/CoinSetRule.h"
#include "../Background/FieldGeneration/Rules/CollapseSetRule.h"
#include "../Background/FieldGeneration/Rules/EnemySpawnRule.h"
#include "../Background/FieldGeneration/Rules/FieldCreaseRule.h"
#include "../Background/FieldGeneration/Rules/HealSetRule.h"
#include "../Background/FieldGeneration/Rules/PlayerSpawnRule.h"
#include "../Background/FieldGeneration/Rules/WallSetRule.h"
#include "../Info/Enums.h"
//FieldGenerator<coin(EASY), clp(EASY), enemy(EASY), crease(EASY), plr(EASY), wall(EASY)>
//        generator;
#define coin(level)  CoinSetRule<level>
#define clp(level)  CollapseSetRule<level>
#define enemy(level)  EnemySpawnRule<level>
#define crease(level)  FieldCreaseRule<level>
#define plr(level)  PlayerSpawnRule<level>
#define wall(level)  WallSetRule<level>
#define heal(level)  HealSetRule<level>

Controller::Controller(LogOutInfo *info, COMPLEXITY comp, int width, int height, int
health, int armour, int damage) {
    this->player = new Player(info, health, armour, damage);
    this->player_view = PlayerView(this->player);
    this->log_out_info = info;
    new GameObserver(this->player);
    this->height = height;
    this->width = width;
    this->complexity = comp;
}

void Controller::show_field() {
    this->field_view.show_field();
    this->player_view.show_chars();
}

void Controller::create_field() {
    Message message(STATUS, "Game started", log_out_info);
    notify(message);
    if (complexity == EASY) {
        FieldGenerator<coin(EASY), clp(EASY), enemy(EASY),
                crease(EASY), plr(EASY), wall(EASY), heal(EASY) > generator;
        this->field = generator.fill(this->log_out_info, this->player, width, height);
    } else {
        FieldGenerator<coin(HARD), clp(HARD), enemy(HARD),
                crease(HARD), plr(HARD), wall(HARD), heal(HARD) > generator;
        this->field = generator.fill(this->log_out_info, this->player, width, height);
    }

    this->field_view = FieldView(this->field);
    new GameObserver(this->field);
    new ErrorsObserver(this->field);
}


bool Controller::move_player(MOVES move) {
    int x = 0;
    int y = 0;
    switch (move) {
        case MOVES::LEFT:
            x -= 1;
            break;
        case MOVES::RIGHT:
            x += 1;
            break;
        case MOVES::UP:
            y -= 1;
            break;
        case MOVES::DOWN:
            y += 1;
            break;
        case MOVES::NOWHERE:
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



