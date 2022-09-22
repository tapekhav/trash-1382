#include "Logging/Commander.h"

void Commander::SetStandardSizeField() {
    mField = Field();
}

void Commander::SetFieldSize(int width, int height) {
    mField = Field(width, height);
}

void Commander::PlayerGo(Direction dir) {
    mGameProgress = mField.MovePlayer(dir);
}

void Commander::ShowField() {
    mView.View(mField);
}