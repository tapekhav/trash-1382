#include "LevelContext.h"

LevelContext::LevelContext(std::unique_ptr<LevelStrategy> &&strategy) : level(std::move(strategy)) {}

void LevelContext::set_strategy(std::unique_ptr<LevelStrategy> &&strategy) {
    level = std::move(strategy);
}

void LevelContext::set_level() {
    field = level->generate_level(width, height);
}

void LevelContext::set_field_size(int width, int height) {
    this->width = width;
    this->height = height;
}

Field *LevelContext::get_field() {
    return field;
}

