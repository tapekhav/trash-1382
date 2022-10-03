#include "Logging/Commander.h"

Commander::Commander() {
    mPlayer = new Player;
    mField = new Field;
    mView = new FieldViewer;
    mStatus = new PlayerViewer;
}

void Commander::SetStandardSizeField() {
    *mField = Field();
}

void Commander::SetFieldSize(int width, int height) {
    *mField = Field(width, height);
}

void Commander::PlayerGo(EnumClass::Direction dir) {
    mField->MovePlayer(dir);
}

void Commander::ShowField() {
    mView->View(*mField);
}

Commander::~Commander() {
    delete mPlayer;
    delete mView;
    delete mStatus;
    delete mField;
}