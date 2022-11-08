#ifndef LABS_TERMINALCONTROLLER_H
#define LABS_TERMINALCONTROLLER_H

#include <iostream>
#include "IController.h"

class TerminalController final : public IController {
public:
    char get_step() final;
    ~TerminalController() final = default;
};


#endif
