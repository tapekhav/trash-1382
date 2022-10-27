#ifndef SURVIVAL_COMMANDER_H
#define SURVIVAL_COMMANDER_H

#include "Field/Field.h"
#include "InputOutput/FieldViewer.h"
#include "InputOutput/PlayerView.h"
#include "Processing/Handle.h"
#include "Event/EventManager.h"
#include "Logging/Logs/LogStatus.h"
#include "Enums.h"

class Commander : public Handle {
public:
    Commander(Observer* logStatus);

    void SetFieldSize(int width, int height);

    void PlayerGo(EnumClass::Direction dir);

    void ShowField();

    void SetMove(int steps);

    ~Commander();

private:
    void CreateMessage(EnumClass::Log type, int pos1, int pos2);
    void SpendEnergy(bool type);

    int mMove;

    Field* mField;
    FieldViewer* mView;
    Player* mPlayer;
    PlayerViewer* mStatus;
    EventManager* mManager;
    Observer* mLogStatus;
};

#endif //SURVIVAL_COMMANDER_H