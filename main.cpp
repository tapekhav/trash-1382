#include "GameControl/ComandController.h"
#include "Input-Output/ComandReader.h"
#include "Mediator/MediatorController.h"
#include "Input-Output/TextOutput.h"

int main(){
ComandReader* comandReader = new ComandReader();
ComandController* comandController = new ComandController();
Game* game = new Game();

MediatorController* mediator = new MediatorController(comandReader, comandController, game);

TextOutput textOut;

textOut.StartText();
game->StartGame();
comandController -> ViewField();


while(game->CheckGameStatus()){
    comandReader -> Read();
    comandController -> ViewField();
}

delete comandReader;
delete comandController;
delete game;
delete mediator;
}