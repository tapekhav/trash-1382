//
// Created by roman on 21.11.2022.
//

#ifndef OOP_HEALSETRULE_H
#define OOP_HEALSETRULE_H

#include "../../Field.h"
#include "../../../Events/PlayerEvents/Heal.h"
#include "../../../Characters/Player.h"

#include "../../../Events/EventBuilder.h"

template<COMPLEXITY comp>
class HealSetRule {
public:
    void operator()(EventBuilder &builder) {
        Field *field = builder.get_field();
        int height = field->get_height();
        int width = field->get_width();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Cell &cell = field->get_cell(x, y);
                if ((x - y) % (4 / comp) == 0 && x % 2 == 0 && y % (4 / comp) == 0 && cell.get_pass() &&
                    field->get_player_x() != x && field->get_player_y() != y && !cell.get_event())
                    cell.set_event(builder.create_HealEvent());
            }
        }
    }
};

#endif //OOP_HEALSETRULE_H
