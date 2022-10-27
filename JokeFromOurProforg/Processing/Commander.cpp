#include "Processing/Commander.h"

Commander::Commander(Observer* logStatus): mLogStatus(logStatus) {
    mPlayer = new Player;
    mPlayer->Attach(mLogStatus);
    mView = new FieldViewer;
    mStatus = new PlayerViewer;
}

void Commander::SetFieldSize(int width, int height) {
    mField = new Field(width, height);
    mField->Attach(mLogStatus);
    mManager = new EventManager(mPlayer, mField);
    mManager->Attach(mLogStatus);
    mField->SetEventManager(mManager);
}

void Commander::PlayerGo(EnumClass::Direction dir) {
    mMediator->Notify(EnumClass::MOVE_COUNT);
    srand(time(0));

    switch (dir)
    {
    case EnumClass::RIGHT:
        if (!mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + 1) % mField->GetHeight()).IsWall())
            mField->SetPlayerPositionX((mField->GetPlayerPositionX() + 1) % mField->GetHeight());
        else
            CreateMessage(EnumClass::LOG_ERROR_WALL, (mField->GetPlayerPositionX() + 1) % mField->GetHeight(), mField->GetPlayerPositionY());
        break;
    case EnumClass::DOWN:
        if (!mField->GetCell((mField->GetPlayerPositionY() + 1) % mField->GetWidth(), mField->GetPlayerPositionX()).IsWall())
            mField->SetPlayerPositionY((mField->GetPlayerPositionY() + 1) % mField->GetWidth());
        else
            CreateMessage(EnumClass::LOG_ERROR_WALL, mField->GetPlayerPositionX(), (mField->GetPlayerPositionY() + 1) % mField->GetWidth());
        break;
    case EnumClass::LEFT:
        if (!mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight()).IsWall())
            mField->SetPlayerPositionX((mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight());
        else
            CreateMessage(EnumClass::LOG_ERROR_WALL, (mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight(), mField->GetPlayerPositionY());
        break;
    case EnumClass::UP:
        if (!mField->GetCell((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth(), mField->GetPlayerPositionX()).IsWall())
            mField->SetPlayerPositionY((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth());
        else
            CreateMessage(EnumClass::LOG_ERROR_WALL, mField->GetPlayerPositionX(), (mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth());
        break;
    default:
        break;
    }
    mField->TriggerCells();
    SpendEnergy(mMove % 2 == 1);
}

void Commander::ShowField() {
   
    mStatus->View(*mPlayer);
    mStatus->PrintStatus(mManager->GetStatus());
    mView->View(*mField);
}

void Commander::SpendEnergy(bool type) {
    mPlayer->LoseThirstUnit();

    if (type)
        mPlayer->LoseHungerUnit();

    if (mPlayer->GetHunger() <= 0 || mPlayer->GetThirst() <= 0)
        mPlayer->DamagePlayer(EnumClass::DAMAGE);
    if (mPlayer->GetHealth() <= 0) {
        ShowField();
        mMediator->Notify(EnumClass::DEFEAT);
    }

}

void Commander::SetMove(int steps) {
    mMove = steps;
}

void Commander::CreateMessage(EnumClass::Log type, int pos1, int pos2) {
    Message* msg = new Message(type);
    msg->IncreaseData(&pos1);
    msg->IncreaseData(&pos2);
    Notify(msg);
    delete msg;
}


Commander::~Commander() {
    mPlayer->Detach(mLogStatus);
    delete mPlayer;
    delete mView;
    delete mStatus;
    delete mField;
    delete mManager;
}