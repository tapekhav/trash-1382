#ifndef LAB2_FIELD_H
#define LAB2_FIELD_H


#include <utility>
#include <vector>
#include <memory>
#include "Cell/Cell.h"
#include "../../../Characters/Player.h"
#include "Cell/CellFactory.h"

#define MINHEIGHT 10
#define MINWIDTH 10


class Field{
private:
    std::pair<int, int> fieldSize;
    std::pair<int, int> playerPosition;
    std::vector<std::vector<Cell>> field;
    CellFactory cellFactory;
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
    std::pair<int, int> getPlayerPosition() const;
    const Cell& getCell(int, int) const;
};


#endif
