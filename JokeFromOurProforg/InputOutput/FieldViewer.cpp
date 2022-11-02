#include "InputOutput/FieldViewer.h"

char FieldViewer::HandleObject(EnumClass::FieldObj type) {
    switch (type)
    {
    case EnumClass::BORDER_ABOVE_AND_BOTTOM:
        return '-';
    case EnumClass::BORDER_LEFT_AND_RIGHT:
        return '|';
    case EnumClass::BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM:
        return '\\';
    case EnumClass::BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE:
        return '/';
    case EnumClass::PLAYER:
        return 'P';
    }
}

void FieldViewer::View(const Field& field) {
    std::cout << HandleObject(EnumClass::BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE) << ' ';
    for (int idx = 0; idx < field.GetHeight(); idx++)
        std::cout << HandleObject(EnumClass::BORDER_ABOVE_AND_BOTTOM) << ' ';
    std::cout << HandleObject(EnumClass::BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM) << std::endl;

    for (int idy = 0; idy < field.GetWidth(); idy++) {
        std::cout << HandleObject(EnumClass::BORDER_LEFT_AND_RIGHT) << ' ';
        for (int idx = 0; idx < field.GetHeight(); idx++) {
            if (field.GetPlayerPositionX() == idx && field.GetPlayerPositionY() == idy)
                std::cout << HandleObject(EnumClass::PLAYER) << ' ';
            else
                std::cout << mCellViewer.View(field.GetCell(idy, idx)) << ' ';
        }
        std::cout << HandleObject(EnumClass::BORDER_LEFT_AND_RIGHT) << std::endl;
    }

    std::cout << HandleObject(EnumClass::BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM) << ' ';
    for (int idx = 0; idx < field.GetHeight(); idx++)
        std::cout << HandleObject(EnumClass::BORDER_ABOVE_AND_BOTTOM) << ' ';
    std::cout << HandleObject(EnumClass::BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE) << std::endl;
}