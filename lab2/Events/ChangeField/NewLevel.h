#ifndef LABS_NEWLEVEL_H
#define LABS_NEWLEVEL_H

#include "EventField.h"

class NewLevel final : public EventField {
public:
    explicit NewLevel(Field* field);
    void execute() final;
};


#endif
