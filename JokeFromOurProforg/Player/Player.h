#ifndef SURVIVAL_PLAYER_H
#define SURVIVAL_PLAYER_H

enum {
    THIRST = 20,
    HUNGER = 10,
    HEALTH = 5
};

class Player {
public:
    Player() :mHealth(HEALTH), mThirst(THIRST), mHunger(HUNGER){};
    Player(const Player& obj);
    Player(Player&& obj);

    Player& operator =(Player const& other);

    int GetHealth() const { return mHealth; }
    int GetHunger() const { return mHunger; }
    int GetThirst() const { return mThirst; }
private:
    int mThirst;
    int mHunger;
    int mHealth;
};

#endif //SURVIVAL_PLAYER_H