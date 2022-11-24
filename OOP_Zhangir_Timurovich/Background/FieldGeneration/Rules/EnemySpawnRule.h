//
// Created by roman on 21.11.2022.
//

#ifndef OOP_ENEMYSPAWNRULE_H
#define OOP_ENEMYSPAWNRULE_H

#include "../../Field.h"
#include "../../../Events/PlayerEvents/Enemy.h"
#include "../../../Characters/Player.h"

#include "../../../Events/EventBuilder.h"

template<COMPLEXITY enemy>
class EnemySpawnRule {
public:
    void operator()(EventBuilder& builder) {
        Field* field = builder.get_field();
        int height = field->get_height();
        int width = field->get_width();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if ((x - y) % (7 / enemy) == 0 && x % (5 / enemy) == 0) {
                    field->get_cell(x, y).set_event(builder.create_EnemyEvent());
                    field->get_cell(x, y).set_pass(true);
                }
            }
        }
    }
};


#endif //OOP_ENEMYSPAWNRULE_H
