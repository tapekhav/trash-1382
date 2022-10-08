#ifndef LABS_ENDGAME_H
#define LABS_ENDGAME_H

#include "EventRule.h"
#include "../../Characters/Player.h"

class EndGame : public EventRule {
public:
    void execute() override;

};


#endif //LABS_ENDGAME_H
