//
// Created by roman on 08.11.2022.
//

#ifndef MAIN_CPP_CONSOLESETTINGS_H
#define MAIN_CPP_CONSOLESETTINGS_H

#include "Settings.h"

class ConsoleSettings : public Settings {
public:
    void set_size() override;

    void set_output() override;

    void set_level() override;

    void set_complexity() override;
};


#endif //MAIN_CPP_CONSOLESETTINGS_H
