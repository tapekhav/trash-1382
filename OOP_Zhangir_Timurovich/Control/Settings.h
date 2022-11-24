//
// Created by roman on 08.11.2022.
//

#ifndef MAIN_CPP_READERSETTINGS_H
#define MAIN_CPP_READERSETTINGS_H

#include "../Logging/Subject.h"
#include "../Info/Enums.h"
#include <vector>

class Settings {
public:
    virtual void set_size() = 0;

    virtual void set_output() = 0;

    virtual void set_level() = 0;

    virtual void set_complexity() = 0;

    [[nodiscard]] virtual int get_width() const;

    [[nodiscard]] virtual int get_height() const;

    [[nodiscard]] virtual COMPLEXITY get_complexity() const;

    virtual std::vector<LEVEL> get_levels();

    virtual std::vector<OUTPUT> get_outputs();

protected:
    int width{};
    int height{};
    COMPLEXITY complexity;
    std::vector<OUTPUT> outputs;
    std::vector<LEVEL> levels;
};


#endif //MAIN_CPP_READERSETTINGS_H
