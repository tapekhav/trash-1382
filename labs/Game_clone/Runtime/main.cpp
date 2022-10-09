#include "Mediator.h"

int main() {
    Controller controller(FieldView(nullptr));
    CommandReader commandReader;

    Mediator mediator(controller, commandReader);
    mediator.start();

    return 0;
};