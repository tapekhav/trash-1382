#ifndef LABS_ORIGINATOR_H
#define LABS_ORIGINATOR_H

#include "Memento.h"


class Originator {
public:
    virtual Memento* save() = 0;
    virtual void restore(Memento*) = 0;
};


#endif
