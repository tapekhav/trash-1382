#include "Logging/Commander.h"

Commander::Commander() {
    mPlayer = new Player;
    mField = new Field;
    mView = new FieldViewer;
    mStatus = new PlayerViewer;
}

void Commander::SetFieldSize(int width, int height) {
    mField = new Field(width, height);
}

void Commander::PlayerGo(EnumClass::Direction dir) {
    switch (dir)
    {
    case EnumClass::RIGHT:
        if (!mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + 1) % mField->GetHeight()).IsWall())
            mField->SetPlayerPositionX((mField->GetPlayerPositionX() + 1) % mField->GetHeight());
        break;
    case EnumClass::DOWN:
        if (!mField->GetCell((mField->GetPlayerPositionY() + 1) % mField->GetWidth(), mField->GetPlayerPositionX()).IsWall())
            mField->SetPlayerPositionY((mField->GetPlayerPositionY() + 1) % mField->GetWidth());
        break;
    case EnumClass::LEFT:
        if (!mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight()).IsWall())
            mField->SetPlayerPositionX((mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight());
        break;
    case EnumClass::UP:
        if (!mField->GetCell((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth(), mField->GetPlayerPositionX()).IsWall())
            mField->SetPlayerPositionY((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth());
        break;
    default:
        break;
    }
    
}

void Commander::ShowField() {
    system("cls");
    mStatus->View(*mPlayer);
    mView->View(*mField);
}

Commander::~Commander() {
    delete mPlayer;
    delete mView;
    delete mStatus;
    delete mField;
}