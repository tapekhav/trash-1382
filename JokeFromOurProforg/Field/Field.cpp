#include "Field/Field.h"

Field::Field(int width, int height) : mPlayerPosition(height / 2, width / 2), mWidth(width), mHeight(height) {
    for (int xIdx = 0; xIdx < mWidth; xIdx++) {
        mField.emplace_back(std::vector<Cell>());
        for (int yIdx = 0; yIdx < mHeight; yIdx++)
            mField[xIdx].push_back(Cell());
    }
    mField[width / 2][height / 2 + 1].SetWall(true);
}

Field& Field::operator=(Field const& other) {
    if (this == &other)
        return *this;
    for (int idx = 0; idx < mWidth; idx++)
        mField[idx].clear();
    mField.clear();
    mWidth = other.mWidth;
    mHeight = other.mHeight;
    for (int idy = 0; idy < mWidth; idy++)
        mField.emplace_back(other.mField[idy]);
    mPlayerPosition.xCoord = other.mPlayerPosition.xCoord;
    mPlayerPosition.yCoord = other.mPlayerPosition.yCoord;
    return *this;
}

Field::Field(const Field& obj) : Field(obj.mWidth, obj.mHeight) {
    for (int yIdx = 0; yIdx < mWidth; yIdx++)
        for (int xIdx = 0; xIdx < mHeight; xIdx++)
            mField[yIdx][xIdx] = obj.mField[yIdx][xIdx];
    mPlayerPosition.xCoord = obj.mPlayerPosition.xCoord;
    mPlayerPosition.yCoord = obj.mPlayerPosition.yCoord;
}

Field::Field(Field&& obj) : Field(obj.mWidth, obj.mHeight) {
    for (int yIdx = 0; yIdx < mWidth; yIdx++) {
        for (int xIdx = 0; xIdx < mHeight; xIdx++)
            mField[yIdx][xIdx] = obj.mField[yIdx][xIdx];
        obj.mField[yIdx].clear();
    }
    obj.mField.clear();
    mPlayerPosition.xCoord = obj.mPlayerPosition.xCoord;
    obj.mPlayerPosition.xCoord = -1;
    mPlayerPosition.yCoord = obj.mPlayerPosition.yCoord;
    obj.mPlayerPosition.yCoord = -1;
}

Cell Field::GetCell(int idy, int idx) const {
    if (idx >= 0 && idx < GetHeight() && idy >= 0 && idy < GetWidth())
        return mField[idy][idx];
}