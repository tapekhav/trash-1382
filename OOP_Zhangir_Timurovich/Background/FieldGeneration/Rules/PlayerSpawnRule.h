//
// Created by roman on 21.11.2022.
//

#ifndef OOP_PLAYERSPAWNRULE_H
#define OOP_PLAYERSPAWNRULE_H

#include "../../Field.h"

#include "../../../Events/EventBuilder.h"

template<COMPLEXITY comp>
class PlayerSpawnRule {
public:
    void operator()(EventBuilder &builder) {
        Field *field = builder.get_field();
        std::random_device dev;
        std::mt19937 rng(dev());
        std::vector<std::vector<int>> free_cells;
        for (int y = 0; y < comp * field->get_height() / 2; y++) {
            for (int x = 0; x < comp * field->get_width() / 2; x++) {
                Cell &cell = field->get_cell(x, y);
                if (cell.get_pass() && !cell.get_event()) {
                    std::vector<int> pair;
                    pair.push_back(x);
                    pair.push_back(y);
                    free_cells.push_back(pair);
                }
            }
        }
        std::uniform_int_distribution<std::mt19937::result_type> spawn(0, free_cells.size()-1);
        std::vector<int> spawn_pair = free_cells.at(spawn(rng));
        int cur_x = spawn_pair.at(0);
        int cur_y = spawn_pair.at(1);
        field->set_player_loc(cur_x, cur_y);
    }
};


#endif //OOP_PLAYERSPAWNRULE_H
