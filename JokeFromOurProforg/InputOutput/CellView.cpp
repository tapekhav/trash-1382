#include "InputOutput/CellView.h"

char CellViewer::View(Cell cell) const{
	if (cell.IsWall())
		return 219;
	else
		return ' ';
}