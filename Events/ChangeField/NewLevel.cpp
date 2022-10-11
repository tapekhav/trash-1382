#include "NewLevel.h"

void NewLevel::execute(Field &field) {
    field.clear_field();
    field.set_player_location();
    field.make_field();
}
