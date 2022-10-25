//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_PERSON_H
#define UNTITLED48_PERSON_H

class Person{
public:
    enum STEP{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        EXIT,
        NOTHING
    };
    explicit Person(int hp = 1, int damage = 1, int xp = 1,int lvl = 1);

    int get_hp()const;
    int get_lvl()const;
    int get_xp()const;
    int get_dmg()const;

    void set_hp(int hp);
    void set_dmg(int dmg);
    void set_lvl(int lvl);
    void set_xp(int xpe);

private:
    int health, xp,damage,lvl;

};

#endif //UNTITLED48_PERSON_H
