//
// Created by ajems on 21.09.22.
//

#ifndef GAME_CELL_H
#define GAME_CELL_H


class Cell{
private:
    bool passable;
    bool stepped;
public:
    explicit Cell(bool passable = true, bool stepped = false);
    bool isPassable() const;
    bool isStepped() const;

    void setStepped();
    void setUnstepped();

};



#endif //GAME_CELL_H
