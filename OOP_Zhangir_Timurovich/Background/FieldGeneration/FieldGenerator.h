//
// Created by roman on 22.11.2022.
//
#pragma once

//#include "../Field.h"
//#include "Rules/WallSetRule.h"
//#include "Rules/HealSetRule.h"
//
//#include "../../Events/EventBuilder.h"
#include "IFieldGenerator.h"

template<class... Rules>
class FieldGenerator : public IFieldGenerator {
public:
    Field *fill(LogOutInfo *info, Player *player, int width, int height) override {
        auto field = new Field(info, width, height);
        EventBuilder builder(field, player);
        field->create_field(player);
        (Rules()(builder), ...);
        return field;
    };
};


