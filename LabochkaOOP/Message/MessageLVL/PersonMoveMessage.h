//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_PERSONMOVEMESSAGE_H
#define LABOCHKAOOP_PERSONMOVEMESSAGE_H
#include "../Message.h"

class HeroMovesMessage : public Message {
public:
    enum type{HERO_MOVE_LEFT, HERO_MOVE_RIGHT, HERO_MOVE_UP, HERO_MOVE_DOWN};
    std::string get_message(int key) override;

};

#endif //LABOCHKAOOP_PERSONMOVEMESSAGE_H
