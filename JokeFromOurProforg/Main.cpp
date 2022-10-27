// Survival.cpp: определяет точку входа для приложения.
//

#include "Main.h"

using namespace std;

int main()
{
	LogManager* manager = new LogManager;
	Commander* commander = new Commander(manager->GetLogStatus());
	commander->Attach(manager->GetLogError());
	CommandReader* commandReader = new CommandReader;
	commandReader->Attach(manager->GetLogError());
	Game* game = new Game;
	game->Attach(manager->GetLogError());
	game->Attach(manager->GetLogGame());
	Mediator* mediator = new HandleMediator(commander, commandReader, game);
	mediator->Attach(manager->GetLogError());

	game->StartGame();

	delete mediator;
	delete commander;
	delete commandReader;
	delete game;
	delete manager;
	return 0;
}
