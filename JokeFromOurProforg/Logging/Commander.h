#ifndef SURVIVAL_COMMANDER_H
#define SURVIVAL_COMMANDER_H

#include "Field/Field.h"
#include "InputOutput/FieldViewer.h"
#include "InputOutput/PlayerView.h"
#include "Logging/Handle.h"
#include "Enums.h"

class Commander : public Handle {
public:
    Commander();

    void SetFieldSize(int width, int height);

    void PlayerGo(EnumClass::Direction dir);

    void ShowField();

    ~Commander();

private:
    Field* mField;
    FieldViewer* mView;
    Player* mPlayer;
    PlayerViewer* mStatus;

};

#endif //SURVIVAL_COMMANDER_H