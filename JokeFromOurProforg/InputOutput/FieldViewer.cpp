#include "InputOutput/FieldViewer.h"

char FieldViewer::HandleObject(FieldObj type) {
    switch (type)
    {
    case BORDER_ABOVE_AND_BOTTOM:
        return '-';
    case BORDER_LEFT_AND_RIGHT:
        return '|';
    case BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM:
        return '\\';
    case BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE:
        return '/';
    case PLAYER:
        return 'P';
    }
}

void FieldViewer::View(const Field& field) {
    system("cls");
    std::cout << HandleObject(BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE) << ' ';
    for (int idx = 0; idx < field.GetHeight(); idx++)
        std::cout << HandleObject(BORDER_ABOVE_AND_BOTTOM) << ' ';
    std::cout << HandleObject(BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM) << std::endl;

    for (int idy = 0; idy < field.GetWidth(); idy++) {
        std::cout << HandleObject(BORDER_LEFT_AND_RIGHT) << ' ';
        for (int idx = 0; idx < field.GetHeight(); idx++) {
            if (field.GetPlayerPositionX() == idx && field.GetPlayerPositionY() == idy)
                std::cout << HandleObject(PLAYER) << ' ';
            else
                std::cout << mCellViewer.View(field.GetCell(field.GetPlayerPositionY(), field.GetPlayerPositionX())) << ' ';
        }
        std::cout << HandleObject(BORDER_LEFT_AND_RIGHT) << std::endl;
    }

    std::cout << HandleObject(BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM) << ' ';
    for (int idx = 0; idx < field.GetHeight(); idx++)
        std::cout << HandleObject(BORDER_ABOVE_AND_BOTTOM) << ' ';
    std::cout << HandleObject(BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE) << std::endl;
}