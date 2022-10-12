#include "CellKey.h"

CellKey::CellKey() {
    event = new Key;
}

Event *CellKey::get_event() {
    return event;
}

CellKey::~CellKey() {
    delete event;
}
