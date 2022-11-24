#ifndef SURVIVAL_COMMANDER_H
#define SURVIVAL_COMMANDER_H

#include "Field/Field.h"

#include "InputOutput/FieldViewer.h"
#include "InputOutput/PlayerView.h"

#include "Processing/Handle.h"

#include "Event/EventManager.h"

#include "Logging/Logger.h"
#include "Logging/Subject.h"
#include "Logging/Messages/ErrorDecorator.h"
#include "Logging/Messages/IntIntMessage.h"

#include "Enums.h"

class Commander : public Handle, public Subject {
public:
    Commander(Logger* logger);

    void SetFieldSize(std::pair<int,int> fieldSize);

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
};

#endif //SURVIVAL_COMMANDER_H