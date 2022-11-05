#ifndef LABS_ICONTROL_H
#define LABS_ICONTROL_H

#include "Player.h"
#include <map>

class IConfig {
public:
    virtual ~IConfig() = default;
    virtual std::map<char, Player::STEP> get_config() = 0;
protected:
    void is_ok();
    bool check_repeats(const std::vector<char>&);

    std::map<char, Player::STEP> control = {
            {'\0', Player::STEP::UP},
            {'\0', Player::STEP::DOWN},
            {'\0', Player::STEP::LEFT},
            {'\0', Player::STEP::RIGHT},
            {'\0', Player::STEP::EXIT}
    };
    const std::map<char, Player::STEP> control_default = {
            {'w', Player::STEP::UP},
            {'s', Player::STEP::DOWN},
            {'a', Player::STEP::LEFT},
            {'d', Player::STEP::RIGHT},
            {'e', Player::STEP::EXIT}
    };
};

#endif
