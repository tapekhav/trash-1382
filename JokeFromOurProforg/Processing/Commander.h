#ifndef SURVIVAL_COMMANDER_H
#define SURVIVAL_COMMANDER_H

#include "InputOutput/FieldViewer.h"
#include "InputOutput/PlayerView.h"

#include "Processing/Handle.h"

#include "Event/EventManager.h"

#include "Logging/Logger.h"
#include "Logging/Subject.h"
#include "Logging/Messages/ErrorDecorator.h"
#include "Logging/Messages/IntIntMessage.h"
#include "Field/LevelManager.h"

#include "Enums.h"

class Commander : public Handle, public Subject {
public:
    Commander(Logger* logger);

    void SetLevel(int num);

    void PlayerGo(EnumClass::Commands dir);

    void ShowField();

    void SetMove(int steps);

    ~Commander();

private:
    void SpendEnergy(bool type);

    int mMove;

    Field* mField;
    FieldViewer* mView;
    Player* mPlayer;
    PlayerViewer* mStatus;
    EventManager* mManager;
    Logger* mLogger;
    LevelManager* mLevel;

};

#endif //SURVIVAL_COMMANDER_H