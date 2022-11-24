//
// Created by roman on 21.11.2022.
//

#ifndef OOP_WALLSETRULE_H
#define OOP_WALLSETRULE_H

#include "../../Field.h"

#include "../../../Events/EventBuilder.h"


template<COMPLEXITY comp>
class WallSetRule {
public:
    void operator()(EventBuilder& builder) {
        Field *field = builder.get_field();
        int height = field->get_height();
        int width = field->get_width();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if ((x + y) % (3 / comp) == 0 && x % 2 == 0 and y % (6 / comp) == 0) {
                    field->get_cell(x, y).set_event(nullptr);
                    field->get_cell(x, y).set_pass(false);
                }
            }
        }
    }
};


#endif //OOP_WALLSETRULE_H
