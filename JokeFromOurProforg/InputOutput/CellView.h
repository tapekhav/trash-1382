#ifndef SURVIVE_CELLVIEWER_H
#define SURVIVE_CELLVIEWER_H

#include "Field/Cell.h"
#include "Event/Bush/Bush.h"
#include "Event/Cave/Cave.h"

class CellViewer {
public:
	char View(Cell cell) const;
};

#endif //SURVIVE_CELLVIEWER_H