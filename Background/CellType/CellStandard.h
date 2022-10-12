#ifndef LABS_CELLSTANDARD_H
#define LABS_CELLSTANDARD_H

#include "CellType.h"

class CellStandard : public CellType {
public:
    CellStandard() = default;
    Event* get_event() override;
    ~CellStandard() override = default;
};

#endif
