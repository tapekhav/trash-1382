#ifndef LABS_RULESPAWNBOX_H
#define LABS_RULESPAWNBOX_H


#include "Field/Field.h"

template<int magic_number, int count>
class RuleSpawnTrap {
    void operator()(Field& field) {
        auto player = field.get_player();

        for (int k = 0; k != count; ++k) {
            for (int i = 1; i != field.get_height(); ++i) {
                for (int j = 0; j != field.get_width(); ++j) {
                    if ((magic_number / i) % field.get_height() % 7 == 0
                        && field.get_cur_cell(i, j).get_event() == nullptr)
                        field.get_cur_cell(i, j).set_event(new Box(player));
                }
            }
        }
    }
};

#endif
