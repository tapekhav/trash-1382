#include "CellTrap.h"

CellTrap::CellTrap() {
    event = new Trap;
}

Event *CellTrap::get_event() {
    return event;
}

CellTrap::~CellTrap() {
    delete event;
}
