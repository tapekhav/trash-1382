#include "GameStatus.h"

GameStatus::GameStatus() : status(ON) {}

void GameStatus::set_status(STATUS status) {
    this->status = status;
}

GameStatus::STATUS GameStatus::get_status() const {
    return status;
}
