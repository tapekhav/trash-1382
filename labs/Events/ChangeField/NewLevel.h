#ifndef LABS_NEWLEVEL_H
#define LABS_NEWLEVEL_H

#include "EventField.h"

class NewLevel : public EventField {
public:
    NewLevel() = default;
    void execute(Field& field) override;
};


#endif
