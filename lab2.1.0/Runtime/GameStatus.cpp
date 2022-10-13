#include <iostream>
#include "GameStatus.h"

bool GameStatus::isEndGame(Field* field, Player* player) const {
    return (isWin(field, player) || isLose(field, player));
}

bool GameStatus::isWin(Field* field, Player* player) const{
    bool win = ((player->getCoins() >= ((field->getFieldSize().first/2)*10)) and (field->getPlayerPosition().first==field->getExitPosition().first and field->getPlayerPosition().second==field->getExitPosition().second));
    if(win)
        std::cout << "You Win!\n";
    else{
        std::cout << "Not win, player position h = " << field->getPlayerPosition().second << " w = " << field->getPlayerPosition().first << " coins required = " << ((field->getFieldSize().first/2)*10) << " player have " << player->getCoins() <<'\n';
        std::cout << (player->getCoins() >= ((field->getFieldSize().first/2)*10)) << (field->getPlayerPosition().first==field->getExitPosition().first and field->getPlayerPosition().second==field->getExitPosition().second) << '\n';
        std:: cout << field->getPlayerPosition().first << '\t' << field->getExitPosition().first << '\t' << field->getPlayerPosition().second << '\t' << field->getExitPosition().second << '\n';
    }
    return win;
}

bool GameStatus::isLose(Field* field, Player* player) const{
    bool loos = (player->getHealth() <= 0);
    if (loos)
        std::cout << "You Lose!\n";
    return loos;
}
