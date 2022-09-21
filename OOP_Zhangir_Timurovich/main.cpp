#include "Field.h"
#include "FieldView.h"
#include "Controller.h"
#include "Mediator.h"

int main() {
    Mediator med;
    med.start();
    med.show_game();
}

