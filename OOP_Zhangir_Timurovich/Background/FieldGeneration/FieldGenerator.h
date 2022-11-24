//
// Created by roman on 22.11.2022.
//
#pragma once

#include "../Field.h"
#include "Rules/WallSetRule.h"
#include "Rules/HealSetRule.h"

#include "../../Events/EventBuilder.h"

template<class... Rules>
class FieldGenerator {
public:
    Field *fill(LogOutInfo *info = nullptr, Player *player = nullptr, int width = 10, int
    height = 10) {
        auto field = new Field(info, width, height);
        EventBuilder builder(field, player);
        field->create_field(player);
        (Rules()(builder), ...);
        return field;
    };
};


