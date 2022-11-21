#ifndef LABS_RULESETWALLS_H
#define LABS_RULESETWALLS_H

#include "../Background/Field/Field.h"

template<int magic_number>
class RuleSpawnWalls {
    void operator()(Field& field) {
        for(int i = 1; i != field.get_height(); ++i)
           for(int j = 0; j != field.get_width(); ++j)
               if ((magic_number/i) % field.get_height() % 3 == 0
               && (magic_number/j) % field.get_width() % 3 == 0 && field.get_cur_cell(i, j).get_event() == nullptr)
                   field.get_cur_cell(i, j).set_pass(false);
    }
};


#endif
