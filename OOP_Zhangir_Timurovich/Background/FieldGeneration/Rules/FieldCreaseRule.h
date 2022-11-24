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
    void operator()(EventBuilder& builder) {
        Field *field = builder.get_field();
        int height = field->get_height();
        int width = field->get_width();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (x == 1 && (y == height / 2 || y == height / (2 * comp))) {
                    field->get_cell(x, y).set_event(builder.create_IncreaseEvent());
                    field->get_cell(x, y).set_pass(true);
                }
                if (x == (width - 1) && (y == (height / 2) || y == height / (2 * comp))) {
                    field->get_cell(x, y).set_event(builder.create_DecreaseEvent());
                    field->get_cell(x, y).set_pass(true);
                }
            }
        }

    }
};


#endif //OOP_FIELDCREASERULE_H
