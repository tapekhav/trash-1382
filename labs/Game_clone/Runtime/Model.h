#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <memory>
#include "Observable.h"
#include "../Background/Field/Field.h"


class Model: public Observable {
private:
    Field field;
    std::shared_ptr<Player> player = std::make_shared<Player>(Player());
public:
    void createField(std::pair<int, int>);
    void movePlayerPosition(char c);
    Field* getField();

};


#endif
