#include "CellBox.h"

CellBox::CellBox() {
    event = new Box;
}

Event *CellBox::get_event() {
    return event;
}
