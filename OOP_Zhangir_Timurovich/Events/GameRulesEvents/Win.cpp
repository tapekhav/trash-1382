#include <iostream>
#include "Win.h"

bool Win::execute(void *obj) {
    if (obj) {
        auto *player = (Player *) obj;
        if (player->get_coins() > 30) {
            std::cout << "YOU WIN\n";
            return true;
        }
    }
    return false;
}
