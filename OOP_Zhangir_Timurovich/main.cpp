#include "Background/Field.h"
#include "Background/FieldView.h"
#include "Control/Controller.h"
#include "Control/Mediator.h"
#include "Info/LogOutInfo.h"
#include "Output/FileOut.h"
#include "Control/ControlConfig/FileConfig.h"
#include "Control/ConsoleSettings.h"

int main() {
    ControlConfig* cfg = new FileConfig("cfg.txt");
    cfg->read_config();
    CommandReader* reader = new ConsoleReader(cfg);
    Settings* settings = new ConsoleSettings;
    settings->set_level();
    settings->set_output();
    settings->set_size();
    LogOutInfo* logout_info = new LogOutInfo(settings->get_outputs(), settings->get_levels());
    Controller controller(logout_info, settings->get_width(), settings->get_height(), 15,
                          10, 10);
    Mediator mediator(controller, reader);
    mediator.start_game();
}

