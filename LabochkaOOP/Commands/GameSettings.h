//
// Created by corvussharp on 22.11.22.
//

#ifndef LABOCHKAOOP_GAMESETTINGS_H
#define LABOCHKAOOP_GAMESETTINGS_H


#include <vector>
#include "../LOG/LogsInfo/Structs.h"
#include "../LOG/Logs/Subject.h"

class GameSettings: public Subject{
public:
    virtual void set_level() = 0;

    virtual void set_output() = 0;
    virtual void set_size() = 0;



    virtual int get_height() const;
    virtual int get_width() const;

    virtual std::vector <LEVEL> get_levels();
    virtual std::vector <OUTPUT> get_outputs();

protected:
    int width;
    std::vector<LEVEL> levels;
    std::vector<OUTPUT> outputs;
    int height;
};


#endif //LABOCHKAOOP_GAMESETTINGS_H
