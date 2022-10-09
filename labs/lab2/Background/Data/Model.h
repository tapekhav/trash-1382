#ifndef LAB2_MODEL_H
#define LAB2_MODEL_H


#include <utility>
#include <memory>
#include "Observable.h"
#include "../Field/Field/Field.h"

class Model: public Observable {
private:
    Field field;
    std::shared_ptr<Player> player;
public:
    Model(std::pair<int, int>);
    void createField(std::pair<int, int>, std::pair<int, int>);
    void movePlayerPosition(char c);
    std::pair<int, int> getPlayerPosition() const;
    const Field* getField();
    bool isEndGame() const;

};


#endif