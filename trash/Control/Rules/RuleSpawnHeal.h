#ifndef LABS_RULESPAWNHEAL_H
#define LABS_RULESPAWNHEAL_H

#include "Field/Field.h"

template<int magic_number, int damage, int count>
class RuleSpawnHeal {
    void operator()(Field& field) {
        auto player = field.get_player();

        for (int k = 0; k != count; ++k) {
            for (int i = 1; i != field.get_height(); ++i) {
                for (int j = 0; j != field.get_width(); ++j) {
                    if ((i * magic_number) % field.get_height() == j + 1
                        && field.get_cur_cell(i, j).get_event() == nullptr) {
                        field.get_cur_cell(i, j).set_event(new Trap(player, damage));
                    }
                }
            }
        }
    }
};


#endif
