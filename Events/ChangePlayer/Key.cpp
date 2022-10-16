#include "Key.h"

void Key::execute(Player &player) {
    player.add_key();
    player.notify();
}