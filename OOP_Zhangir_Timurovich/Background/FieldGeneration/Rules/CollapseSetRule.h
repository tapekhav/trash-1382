//
// Created by roman on 21.11.2022.
//
#pragma once

#include "../../Field.h"
#include "../../../Events/FieldEvents/Collapse.h"

#include "../../../Events/EventBuilder.h"

template<COMPLEXITY comp>
class CollapseSetRule {
public:
    void operator()(EventBuilder &builder) {
        Field *field = builder.get_field();
        int height = field->get_height();
        int width = field->get_width();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Cell &cell = field->get_cell(x, y);
                if ((x == 1 || (x == field->get_width() - 1)) &&
                    ((y == 1 || (y == field->get_height() - 1))) ||
                    ((y == (field->get_height() - 1) / comp) &&
                     (x == ((field->get_width() - 1) / comp))) && cell.get_pass() &&
                    field->get_player_x() != x && field->get_player_y() != y && !cell.get_event())
                    cell.set_event(builder.create_CollapseEvent());
            }
        }
    }
};