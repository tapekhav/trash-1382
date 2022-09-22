#ifndef SURVIVAL_FIELD_H
#define SURVIVAL_FIELD_H

#include "Player/Player.h"
#include "Event/Event.h"

#include <vector>
#include <cmath>

enum {
    STANDARD_SIZE = 15
};

enum CellType {
    EMPTY,
    WALL,
    EVENT
};

enum Direction {
    RIGHT,
    UP,
    LEFT,
    DOWN
};

struct Position {
    int xCoord, yCoord;

    Position(int xCoord, int yCoord) : xCoord(xCoord), yCoord(yCoord) {}
};

class Field {
public:
    explicit Field(int w = STANDARD_SIZE, int h = STANDARD_SIZE);
    Field(const Field& obj);
    Field(Field&& obj);

    Field& operator =(Field const& other);

    bool MovePlayer(Direction dir);

    int GetWidth() const { return mWidth; }
    int GetHeight() const { return mHeight; }
    int GetPlayerPositionX() const { return mPlayerPosition.xCoord; }
    int GetPlayerPositionY() const { return mPlayerPosition.yCoord; }
    CellType GetCellType(int yCoord, int xCoord) const { return mField[yCoord][xCoord].GetType(); }
    int GetPlayerHunger() const { return mPlayer.GetHunger(); }
    int GetPlayerHealth() const { return mPlayer.GetHealth(); }
    int GetPlayerThirsty() const { return mPlayer.GetThirst(); }
    int GetPlayerStepSize() const { return mPlayer.GetStepSize(); }
private:
    class Cell {
    public:
        Cell() : mType(EMPTY) {};
        Cell(const Cell& obj);

        Cell& operator =(Cell const& other);

        CellType GetType() const { return mType; }

        void SetEvent(CellType typeEvent);

        bool ActiveEvent();

    private:
        CellType mType;
        Event* mEvent;
    };

    std::vector<std::vector<Cell>> mField;
    int mWidth, mHeight;
    Player mPlayer;
    Position mPlayerPosition;
};

#endif //SURVIVAL_FIELD_H