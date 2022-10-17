#include "Game.h"
Game::Game(): GameStatus(true){}

void Game::StartGame(){
    std::cin>>StartGameSymbol;
    if(StartGameSymbol == 'Y')
        mediator -> LargeCommandNotify(this,"CreateField");
    else if(StartGameSymbol == 'N')
        mediator -> LargeCommandNotify(this, "CreateStandartField");
    else{
        std::cout<<"Введите Y/N\n";
        StartGame();
    }
}

void Game::setMediator(Mediator* med){
     mediator = med;
}

void Game::QuitGame(){
    GameStatus = false;
}

bool Game::CheckGameStatus(){
    return GameStatus;
}