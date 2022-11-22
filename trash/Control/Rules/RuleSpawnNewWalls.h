#ifndef LABS_RULESPAWNNEWWALLS_H
#define LABS_RULESPAWNNEWWALLS_H

#include "Field/Field.h"

template<int magic_number>
class RuleSpawnNewWalls {
    void operator()(Field &field) {
        auto player = field.get_player();
        int flag = 0;

        for (int i = 1; i != field.get_height(); ++i) {
            for (int j = 0; j != field.get_width(); ++j) {
                if (flag == 1) return;
                if ((i / magic_number) % field.get_height() % 5 == 1
                    && (j / magic_number) % field.get_width() % 5 == 1) {
                    field.get_cur_cell(j, i).set_pass(true);
                    field.get_cur_cell(j, i).set_event(new SetWalls(&field));
                    flag = 1;
                }
            }
        }
    }
};


#endif
