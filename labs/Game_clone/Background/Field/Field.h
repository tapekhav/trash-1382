#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <memory>
#include "vector"
#include "../Cell/Cell.h"
#include "iostream"
#include "../../Characters/Player.h"

#define MINHEIGHT 10
#define MINWIDTH 10


class Field{
private:
    std::pair<int, int> fieldSize;
    std::pair<int, int> playerPosition;
    std::vector<std::vector<Cell*>> field;
public:
    Field(std::pair<int, int> fieldSize = {MINWIDTH, MINHEIGHT},
          std::pair<int, int> playerPosition = {0, 0});

    Field(const Field&);
    void swap(Field&);
    Field& operator=(const Field&);
    Field(Field&&);
    Field& operator=(Field&&);

    void setField();
    void movePlayer(Player::STEP, std::shared_ptr<Player> player);

    std::pair<int, int> getFieldSize() const;
    const Cell& getCell(int, int) const;
};


#endif