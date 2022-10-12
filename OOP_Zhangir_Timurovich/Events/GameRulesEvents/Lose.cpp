//
// Created by roman on 12.10.2022.
//

#include <iostream>
#include "Lose.h"

bool Lose::execute(void *obj) {
    if (obj) {
        auto *player = (Player *) obj;
        if (player->get_health() <= 0){
            std::cout << "YOU LOSE\n";
            return true;
        }
    }
    return false;
}
