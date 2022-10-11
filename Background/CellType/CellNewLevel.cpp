#include "CellNewLevel.h"

CellNewLevel::CellNewLevel() {
    event = new NewLevel;
}

Event *CellNewLevel::get_event() {
    return event;
}
