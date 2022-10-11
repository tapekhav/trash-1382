#include "EventField.h"

void EventField::callReaction(void *obj) {
    auto* field = (Field*) obj;
    changeField(field);
}
