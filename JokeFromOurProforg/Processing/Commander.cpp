#include "Processing/Commander.h"

Commander::Commander(Logger* logger) : mLogger(logger) {
    mPlayer = new Player;
    mPlayer->Attach(mLogger->GetStatusLogger());
    mView = new FieldViewer;
    mStatus = new PlayerViewer;
}

void Commander::SetFieldSize(std::pair<int,int> fieldSize) {
    mField = new Field(fieldSize.first, fieldSize.second);
    mField->Attach(mLogger->GetStatusLogger());
    mManager = new EventManager(mPlayer, mField, mLogger);
    mManager->Attach(mLogger->GetStatusLogger());
    mField->SetEventManager(mManager);
}

void Commander::PlayerGo(EnumClass::Commands dir) {
    mMediator->Notify(EnumClass::MOVE_COUNT);
    srand(time(0));

    switch (dir)
    {
    case EnumClass::RIGHT:
        if (!mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + 1) % mField->GetHeight()).IsWall())
            mField->SetPlayerPositionX((mField->GetPlayerPositionX() + 1) % mField->GetHeight());
        else {
            Message* msg = new ErrorDecorator(new IntIntMessage((mField->GetPlayerPositionX() + 1) % mField->GetHeight(), mField->GetPlayerPositionY(), "Attempt to go to the wall on the position"));
            Notify(msg);
            delete msg;
        }
        break;
    case EnumClass::DOWN:
        if (!mField->GetCell((mField->GetPlayerPositionY() + 1) % mField->GetWidth(), mField->GetPlayerPositionX()).IsWall())
            mField->SetPlayerPositionY((mField->GetPlayerPositionY() + 1) % mField->GetWidth());
        else {
            Message* msg = new ErrorDecorator(new IntIntMessage(mField->GetPlayerPositionX(), (mField->GetPlayerPositionY() + 1) % mField->GetWidth(), "Attempt to go to the wall on the position"));
            Notify(msg);
            delete msg;
        }
        break;
    case EnumClass::LEFT:
        if (!mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight()).IsWall())
            mField->SetPlayerPositionX((mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight());
        else {
            Message* msg = new ErrorDecorator(new IntIntMessage((mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight(), mField->GetPlayerPositionY(), "Attempt to go to the wall on the position"));
            Notify(msg);
            delete msg;
        }
        break;
    case EnumClass::UP:
        if (!mField->GetCell((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth(), mField->GetPlayerPositionX()).IsWall())
            mField->SetPlayerPositionY((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth());
        else {
            Message* msg = new ErrorDecorator(new IntIntMessage(mField->GetPlayerPositionX(), (mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth(), "Attempt to go to the wall on the position"));
            Notify(msg);
            delete msg;
        }
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


Commander::~Commander() {
    delete mPlayer;
    delete mView;
    delete mStatus;
    delete mField;
    delete mManager;
}