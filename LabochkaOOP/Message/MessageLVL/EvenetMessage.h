//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_EVENETMESSAGE_H
#define LABOCHKAOOP_EVENETMESSAGE_H
#include "../Message.h"

class EventMessage : public Message{
public:
    enum type{HEAL, XP, ENEMY, TELEPORT, WIN, REFRESHER, CURE, DEATH, VICTORY};
    std::string get_message(int type) override;
};


#endif //LABOCHKAOOP_EVENETMESSAGE_H
