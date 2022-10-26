//
// Created by corvussharp on 26.10.22.
//

#include "EvenetMessage.h"

std::string EventMessage::get_message(int key) {
    switch (key) {
        case type::HEAL:
            return "[EVENT] Hero was healed by Healing.";
        case type::XP:
            return "[EVENT] Hero got plus one XP.";
        case type::ENEMY:
            return "[EVENT] Hero was hit by Enemy.";
        case type::TELEPORT:
            return "[EVENT] Hero was Teleported.";
        case type::WIN:
            return "[EVENT] Hero moved to the victory cell.";
        case type::REFRESHER:
            return "[EVENT] Hero ate some magic shroom... new objects were spawned at the field.";
        case type::CURE:
            return "[EVENT] Hero was Cured by Blood.";
        case type::DEATH:
            return "HERO IS DEAD!";
        case type::VICTORY:
            return "HERO FINALLY GOT BEER!";
        default:
            return "[ERROR] Bad Argument for Event Log!";
    }
}