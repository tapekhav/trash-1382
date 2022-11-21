#ifndef LABS_DELWALLS_H
#define LABS_DELWALLS_H

#include "EventField.h"
#include "Field/Field.h"

class RuleDelWalls final : public EventField {
public:
    explicit RuleDelWalls(Field*);
    void execute() final;
};


#endif
