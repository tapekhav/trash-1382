//
// Created by corvussharp on 09.10.22.
//

#ifndef LABOCHKAOOP_ENEMY_H
#define LABOCHKAOOP_ENEMY_H


class Enemy {
private:
    int hp, dmg;
public:
    explicit Enemy (int hp = 1, int dmg = 1);
    int get_hp() const;
    int get_dmg() const;
};


#endif //LABOCHKAOOP_ENEMY_H
