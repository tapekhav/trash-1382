#include "Field/Field.h"

Field::Field(int width, int height) : mPlayerPosition(height / 2, width / 2), mWidth(width), mHeight(height) {
    for (int xIdx = 0; xIdx < mWidth; xIdx++) {
        mField.emplace_back(std::vector<Cell>());
        for (int yIdx = 0; yIdx < mHeight; yIdx++)
            mField[xIdx].push_back(Cell());
    }
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
    mPlayer = other.mPlayer;
    return *this;
}

Field::Field(const Field& obj) : Field(obj.mWidth, obj.mHeight) {
    for (int yIdx = 0; yIdx < mWidth; yIdx++)
        for (int xIdx = 0; xIdx < mHeight; xIdx++)
            mField[yIdx][xIdx] = obj.mField[yIdx][xIdx];
    mPlayerPosition.xCoord = obj.mPlayerPosition.xCoord;
    mPlayerPosition.yCoord = obj.mPlayerPosition.yCoord;
    mPlayer = obj.mPlayer;
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
    mPlayer = obj.mPlayer;
}

bool Field::MovePlayer(Direction dir) {
    if (dir == RIGHT) {
        if (mField[mPlayerPosition.yCoord][(mPlayerPosition.xCoord + 1) % mHeight].IsWall())
            return false;
        mPlayerPosition.xCoord = (mPlayerPosition.xCoord + 1) % mHeight;
    }
    else if (dir == UP) {
        if (mField[(mPlayerPosition.yCoord + mWidth - 1) % mWidth][mPlayerPosition.xCoord].IsWall())
            return false;
        mPlayerPosition.yCoord = (mPlayerPosition.yCoord + mWidth - 1) % mWidth;
    }
    else if (dir == LEFT) {
        if (mField[mPlayerPosition.yCoord][(mPlayerPosition.xCoord + mHeight - 1) % mHeight].IsWall())
            return false;
        mPlayerPosition.xCoord = (mPlayerPosition.xCoord + mHeight - 1) % mHeight;
    }
    else {
        if (mField[(mPlayerPosition.yCoord + 1) % mWidth][mPlayerPosition.xCoord].IsWall())
            return false;
        mPlayerPosition.yCoord = (mPlayerPosition.yCoord + 1) % mWidth;
    }
    mField[mPlayerPosition.yCoord][mPlayerPosition.xCoord].ActiveEvent();
    return true;
}

Cell Field::GetCell(int idy, int idx) const {
    if (idx >= 0 && idx < GetHeight() && idy >= 0 && idy < GetWidth())
        return mField[idy][idx];
}