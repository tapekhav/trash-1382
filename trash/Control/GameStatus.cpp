#include "GameStatus.h"

GameStatus::GameStatus() : status(ON) {
    this->notify(Message("Status", "game status is ON"));
}

void GameStatus::set_status(STATUS status) {
    this->status = status;
    this->notify(Message("Status", "game status was changed"));
}

GameStatus::STATUS GameStatus::get_status() const {
    return status;
}
