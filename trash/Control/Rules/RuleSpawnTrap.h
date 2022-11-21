#ifndef LABS_RULESPAWNTRAP_H
#define LABS_RULESPAWNTRAP_H

#include <utility>
#include "Field/Field.h"
#include "../Characters/Player.h"

template<int magic_number, int count>
class RuleSpawnTrap {
    void operator()(Field& field) {
        for (int k = 0; k != count; ++k) {
            for (int i = 1; i != field.get_height(); ++i) {
                for (int j = 0; j != field.get_width(); ++j) {
                    if ((i * magic_number) % field.get_height() == j + 1
                        && field.get_cur_cell(i, j).get_event() == nullptr) {}
                        //field->get_cur_cell(i, j).set_event(new Trap(player))
                }
            }
        }
    }
};

#endif
