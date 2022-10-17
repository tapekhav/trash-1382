#ifndef GAME_H
#define GAME_H
#include "../Mediator/MediatorObj.h"
#include "../Input-Output/ComandReader.h"

class Game : public MediatorObj{
private:
    bool GameStatus;
    char StartGameSymbol;

public:
    Game();
    void StartGame();
    void QuitGame();
    void setMediator(Mediator* med);
    bool CheckGameStatus();
};

#endif
