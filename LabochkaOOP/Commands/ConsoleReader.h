//
// Created by corvussharp on 22.11.22.
//

#ifndef LABOCHKAOOP_CONSOLEREADER_H
#define LABOCHKAOOP_CONSOLEREADER_H
#include "CommandRead.h"

class ConsoleReader: public CommandRead{
public:
    ~ConsoleReader() override = default;
    explicit ConsoleReader(ControlConfig *cfg = nullptr);
    CONTROL read_step()override;
    void set_config(ControlConfig *config);
    CONTROL get_step();
    char get_sym();
    char field_choice();
private:
    char sym{};
    CONTROL step;
};


#endif //LABOCHKAOOP_CONSOLEREADER_H
