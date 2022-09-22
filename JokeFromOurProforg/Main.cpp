// Survival.cpp: определяет точку входа для приложения.
//

#include "Main.h"

using namespace std;

int main()
{
	Commander* commander = new Commander;
	CommandReader* commandReader = new CommandReader;
	Game* game = new Game;
	Mediator* mediator = new HandleMediator(commander, commandReader, game);

	game->StartGame();

	delete mediator;
	delete commander;
	delete commandReader;
	delete game;
	return 0;
}
