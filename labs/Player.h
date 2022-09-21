#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


class Player{
public:
    enum Gender{MAN, WOMAN, HELICOPTER, NONBINARY};
    enum Rank{PRIVATE = 0, CORPORAL = 1, SERGEANT = 2, FOREMAN = 3, ENSIGN = 4, LIEUTENANT = 5, CAPTAIN = 6, MAJOR = 7, COLONEL = 8, GENERAL = 9, MARSHAL = 10};
    explicit Player(unsigned int health = 100,
           unsigned int shield = 0,
           unsigned int damage = 10,
           unsigned int xp = 0,
           Gender gender = NONBINARY);

    unsigned int getHealth() const;
    unsigned int getShield() const;
    unsigned int getDamage() const;

    Gender getGender() const;

    void setHealth(unsigned int health);
    void setShield(unsigned int shield);
    void setDamage(unsigned int damage);

    void addHealth(unsigned int health);
    void addShield(unsigned int shield);
    void addXp(unsigned int xp);


private:
    unsigned int health;
    unsigned int shield;
    unsigned int damage;
    unsigned int xp;
    Gender gender;
};


#endif
