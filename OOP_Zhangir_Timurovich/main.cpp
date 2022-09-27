#include "Background/Field.h"
#include "Background/FieldView.h"
#include "Control/Controller.h"
#include "Control/Mediator.h"

int main() {
    Mediator med;
    med.start();
    med.show_game();
}

