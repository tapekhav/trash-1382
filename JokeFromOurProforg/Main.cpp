// Survival.cpp: определяет точку входа для приложения.
//

#include "Main.h"

using namespace std;

int main(){
	Logger* logs = new Logger;

	Commander* commander = new Commander(logs);
	commander->Attach(logs->GetErrorLogger());

	CommandReader* commandReader = new CommandReader;
	commandReader->Attach(logs->GetErrorLogger());

	Game* game = new Game;
	game->Attach(logs->GetGameLogger());

	Mediator* mediator = new HandleMediator(commander, commandReader, game);

	game->StartGame();

	delete mediator;
	delete commander;
	delete commandReader;
	delete game;
	delete logs;
	return 0;
}
