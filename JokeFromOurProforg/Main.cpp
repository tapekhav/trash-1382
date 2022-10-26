// Survival.cpp: определяет точку входа для приложения.
//

#include "Main.h"

using namespace std;

int main()
{
	LogManager* manager = new LogManager;
	Commander* commander = new Commander(manager->GetLogStatus());
	CommandReader* commandReader = new CommandReader;
	Game* game = new Game;
	Mediator* mediator = new HandleMediator(commander, commandReader, game);

	game->StartGame();

	delete mediator;
	delete commander;
	delete commandReader;
	delete game;
	delete manager;
	return 0;
}
