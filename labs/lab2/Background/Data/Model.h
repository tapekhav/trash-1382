#ifndef LAB2_MODEL_H
#define LAB2_MODEL_H


#include <utility>
#include <memory>
#include "Observable.h"
#include "../Field/Field/Field.h"

class Model: public Observable {
private:
    Field field;
    std::shared_ptr<Player> player = std::make_shared<Player>(Player());
public:
    Model(std::pair<int, int>);
    void createField(std::pair<int, int>);
    void movePlayerPosition(char c);
    Field* getField();

};


#endif