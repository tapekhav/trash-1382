#include "InputOutput/CellView.h"

char CellViewer::View(Cell cell) const{
	if (cell.IsWall())
		return 219;
	else if (dynamic_cast<Bush*>(cell.GetEvent()) != nullptr)
		return '@';
	else if (dynamic_cast<Cave*>(cell.GetEvent()) != nullptr)
		return 'O';
	else
		return ' ';
}