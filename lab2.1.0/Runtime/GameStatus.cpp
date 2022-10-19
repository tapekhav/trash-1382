#include <iostream>
#include "GameStatus.h"

bool GameStatus::isEndGame(Field* field, Player* player) const {
    bool win = isWin(field, player);
    if (win) std::cout << "You Win!\n";
    bool loose = isLoose(field, player);
    if (loose) std::cout << "You Lose!\n";
    return (win || loose);
}

bool GameStatus::isWin(Field* field, Player* player) const{
    bool win = ((player->getCoins() >= ((field->getFieldSize().first/2)*10)) and (field->getPlayerPosition().first==field->getExitPosition().first and field->getPlayerPosition().second==field->getExitPosition().second));
    return win;
}

bool GameStatus::isLoose(Field* field, Player* player) const{
    bool loose = (player->getHealth() <= 0);
    return loose;
}
