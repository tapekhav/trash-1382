#include "CellHeal.h"

CellHeal::CellHeal() {
    event = new Heal;
}

Event *CellHeal::get_event() {
    return event;
}

CellHeal::~CellHeal() {
    delete event;
}
