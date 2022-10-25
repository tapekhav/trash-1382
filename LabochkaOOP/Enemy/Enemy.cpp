//
// Created by corvussharp on 09.10.22.
//
#include "Enemy.h"

int Enemy::get_hp() const {
    return hp;
}
int Enemy::get_dmg() const {
    return dmg;
}
    Enemy::Enemy(int hp, int dmg): hp(hp),dmg(dmg) {

}
