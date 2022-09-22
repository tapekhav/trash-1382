#ifndef SURVIVAL_PLAYER_H
#define SURVIVAL_PLAYER_H

enum {
    THIRST = 20,
    HUNGER = 10,
    HEALTH = 5,
    STEP_SIZE = 1
};

class Player {
public:
    Player() :mHealth(HEALTH), mThirst(THIRST), mHunger(HUNGER), mStepSize(STEP_SIZE) {};
    Player(const Player& obj);
    Player(Player&& obj);

    Player& operator =(Player const& other);

    int GetHealth() const { return mHealth; }
    int GetHunger() const { return mHunger; }
    int GetThirst() const { return mThirst; }
    int GetStepSize() const { return mStepSize; }
private:
    int mThirst;
    int mHunger;
    int mHealth;
    int mStepSize;
};

#endif //SURVIVAL_PLAYER_H