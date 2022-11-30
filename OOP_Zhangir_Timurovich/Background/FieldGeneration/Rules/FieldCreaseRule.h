//
// Created by roman on 21.11.2022.
//

#ifndef OOP_FIELDCREASERULE_H
#define OOP_FIELDCREASERULE_H

#include "../../Field.h"
#include "../../../Events/FieldEvents/Increase.h"
#include "../../../Events/FieldEvents/Decrease.h"
#include "../../../Characters/Player.h"

#include "../../../Events/EventBuilder.h"

template<COMPLEXITY comp>
class FieldCreaseRule {
public:
    void operator()(EventBuilder &builder) {
        Field *field = builder.get_field();
        int height = field->get_height();
        int width = field->get_width();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Cell &cell = field->get_cell(x, y);
                if (cell.get_pass() && field->get_player_x() != x
                    && field->get_player_y() != y && !cell.get_event()) {
                    if (x == 1 && (y == height / 2 || y == height / (2 * comp)))
                        cell.set_event(builder.create_IncreaseEvent());
                    if (x == (width - 1) && (y == (height / 2) || y == height / (2 * comp)))
                        cell.set_event(builder.create_DecreaseEvent());
                }
            }
        }

    }
};


#endif //OOP_FIELDCREASERULE_H
