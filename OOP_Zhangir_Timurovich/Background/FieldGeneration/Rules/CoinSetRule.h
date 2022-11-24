//
// Created by roman on 21.11.2022.
//

#ifndef OOP_COINSETRULE_H
#define OOP_COINSETRULE_H

#include "../../Field.h"
#include "../../../Events/PlayerEvents/GetCoin.h"
#include "../../../Characters/Player.h"
#include "../../../Events/EventBuilder.h"

template<COMPLEXITY comp>
class CoinSetRule {
public:
    void operator()(EventBuilder& builder) {
        Field *field = builder.get_field();
        int height = field->get_height();
        int width = field->get_width();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if ((x + y) % (4 / comp) == 0 && x % (6 / comp) == 0) {
                    field->get_cell(x, y).set_event(builder.create_CoinEvent());
                    field->get_cell(x, y).set_pass(true);
                }
            }
        }
    }
};


#endif //OOP_COINSETRULE_H
