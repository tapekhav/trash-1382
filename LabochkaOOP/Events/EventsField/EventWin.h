//
// Created by corvussharp on 11.10.22.
//

#ifndef LABOCHKAOOP_EVENTWIN_H
#define LABOCHKAOOP_EVENTWIN_H

#include "../../Field/Field.h"
class Field;

class EventWin: public EventField {
public:
    void change_map(Field* field) override;
};


#endif //LABOCHKAOOP_EVENTWIN_H
