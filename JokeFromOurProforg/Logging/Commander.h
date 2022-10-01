#ifndef SURVIVAL_COMMANDER_H
#define SURVIVAL_COMMANDER_H

#include "Field/Field.h"
#include "InputOutput/FieldViewer.h"
#include "Logging/Handle.h"
#include "Enums.h"

class Commander : public Handle {
public:
    Commander() : mGameProgress(true) {}

    void SetStandardSizeField();
    void SetFieldSize(int width, int height);

    void PlayerGo(EnumClass::Direction dir);

    void ShowField();

    bool GetGameProgress() const { return mGameProgress; }
    void SetGameProgress(bool val) { mGameProgress = val; }
private:
    Field mField;
    bool mGameProgress;
    FieldViewer mView;
};

#endif //SURVIVAL_COMMANDER_H