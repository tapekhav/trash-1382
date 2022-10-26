#ifndef LABS_GAMESTATUS_H
#define LABS_GAMESTATUS_H

#include "../Logging/LogLevel/Subject.h"
#include "../Logging/LogLevel/StatusLog.h"

class GameStatus : public Subject {
public:
    enum STATUS {
        ON,
        LOSE,
        WIN
    };

    GameStatus();

    void set_status(GameStatus::STATUS);
    STATUS get_status() const;
private:
    STATUS status;
};


#endif
