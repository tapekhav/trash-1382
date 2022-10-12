#include "Background/Field.h"
#include "Background/FieldView.h"
#include "Control/Controller.h"
#include "Control/Mediator.h"

int main() {
    CommandReader reader;
    reader.set_size();
    Controller controller(reader.get_width(), reader.get_height(), 5, 10, 10);
    Mediator mediator(controller, reader);
    mediator.start_game();
    std::cout << "GAME OVER\n";
}

