#include "EnemyType.h"

bool EnemyType::get_pass() {
    return this->pass;
}

//Event *EnemyType::get_event() {
//    return this->event;
//}

EnemyType::EnemyType() {
    this->pass = true;
//    this->event = new Enemy;
}
