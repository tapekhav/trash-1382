#include <iostream>
#include "GameStatus.h"

bool GameStatus::isEndGame(Field* field, Player* player) const {
    return (isWin(field, player) || isLose(field, player));
}

bool GameStatus::isWin(Field* field, Player* player) const{
    bool win = ((player->getCoins() >= ((field->getFieldSize().first/2)*10)) and (field->getPlayerPosition().first==field->getExitPosition().first and field->getPlayerPosition().second==field->getExitPosition().second));
    if(win)
        std::cout << "You Win!\n";
    return win;
}

bool GameStatus::isLose(Field* field, Player* player) const{
    bool loos = (player->getHealth() <= 0);
    if (loos)
        std::cout << "You Lose!\n";
    return loos;
}
