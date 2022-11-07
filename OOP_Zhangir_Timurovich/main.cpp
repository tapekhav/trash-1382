#include "Background/Field.h"
#include "Background/FieldView.h"
#include "Control/Controller.h"
#include "Control/Mediator.h"
#include "Info/LogOutInfo.h"
#include "Output/FileOut.h"
#include "Control/ControlConfig/FileConfig.h"

int main() {
    ControlConfig* cfg = new FileConfig("cfg.txt");
    cfg->read_config();
    ConsoleReader reader(cfg);
    reader.set_size();
    reader.set_level();
    reader.set_output();
    LogOutInfo* logout_info = new LogOutInfo(reader.get_outputs(), reader.get_levels());
    Controller controller(logout_info, reader.get_width(), reader.get_height(), 15,
                          10, 10);
    Mediator mediator(controller, reader);
    mediator.start_game();
}

