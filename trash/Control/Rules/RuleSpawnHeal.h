#ifndef LABS_RULESPAWNHEAL_H
#define LABS_RULESPAWNHEAL_H

#include "Field/Field.h"

template<int magic_number, int max_count>
class RuleSpawnHeal {
    void operator()(Field& field) {
        auto player = field.get_player();
        int k = 0;

        for (int i = 1; i != field.get_height(); ++i) {
            for (int j = 0; j != field.get_width(); ++j) {
                if (k == max_count) return;
                if ((j + magic_number) % field.get_width() == i
                    && field.get_cur_cell(j, i).get_event() == nullptr) {
                    field.get_cur_cell(j, i).set_event(new Heal(player));
                    ++k;
                }
            }
        }
    }

};


#endif
