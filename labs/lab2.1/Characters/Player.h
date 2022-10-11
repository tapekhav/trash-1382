#ifndef LAB2_PLAYER_H
#define LAB2_PLAYER_H


class Player{
public:
    enum STEP{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NOTHING
    };

    Player(int health = 100,
           int shield = 0,
           int xp = 0,
           int coins = 0);

    int getHealth() const;
    int getShield() const;
    int getXp() const;
    int getCoins() const;


    void addHealth(int health);
    void addShield(int shield);
    void addXp(int xp);
    void addCoins(int coins);

    void downHealth(int health);
    void downShield(int health);

    void roundValue(int& value);

private:
    int health;
    int shield;
    int xp;
    int coins;
};


#endif

