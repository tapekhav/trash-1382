//
// Created by roman on 21.11.2022.
//

#ifndef OOP_PLAYERSPAWNRULE_H
#define OOP_PLAYERSPAWNRULE_H

#include "../../Field.h"

#include "../../../Events/EventBuilder.h"

template<COMPLEXITY comp>
class PlayerSpawnRule {
public:
    void operator()(EventBuilder& builder) {
        Field *field = builder.get_field();
        int cur_x = field->get_width() - field->get_width() / comp + 1;
        int cur_y = field->get_height() - field->get_height() / comp + 1;
        field->get_cell(cur_x, cur_y).set_event(nullptr);
        field->get_cell(cur_x, cur_y).set_pass(true);
        field->set_player_loc(cur_x, cur_y);
    }
};


#endif //OOP_PLAYERSPAWNRULE_H
