#include "InputOutput/FieldViewer.h"

char FieldViewer::HandleView(CellType type) const {
    switch (type) {
    case EMPTY:
        return EMPTY_CELL;
    case WALL:
        return WALL_CELL;
    case EVENT:
        return EVENT_CELL;
    }
}

void FieldViewer::View(const Field& field) {
    system("cls");
    std::cout << (char)BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE << ' ';
    for (int idx = 0; idx < field.GetHeight(); idx++)
        std::cout << (char)BORDER_ABOVE_AND_BOTTOM << ' ';
    std::cout << (char)BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM << std::endl;

    for (int idy = 0; idy < field.GetWidth(); idy++) {
        std::cout << (char)BORDER_LEFT_AND_RIGHT << ' ';
        for (int idx = 0; idx < field.GetHeight(); idx++) {
            if (field.GetPlayerPositionX() == idx && field.GetPlayerPositionY() == idy)
                std::cout << (char)PLAYER << ' ';
            else
                std::cout << (char)HandleView(field.GetCellType(idy, idx)) << ' ';
        }
        std::cout << (char)BORDER_LEFT_AND_RIGHT << std::endl;
    }

    std::cout << (char)BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM << ' ';
    for (int idx = 0; idx < field.GetHeight(); idx++)
        std::cout << (char)BORDER_ABOVE_AND_BOTTOM << ' ';
    std::cout << (char)BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE << std::endl;
}