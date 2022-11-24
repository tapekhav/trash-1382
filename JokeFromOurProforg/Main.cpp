// Survival.cpp: определяет точку входа для приложения.
//

#include "Main.h"

using namespace std;

int main(){
	Logger* logs = new Logger;

	Commander* commander = new Commander(logs);
	commander->Attach(logs->GetErrorLogger());

	InputCenter* inputCenter = new InputCenter;
	inputCenter->Attach(logs->GetErrorLogger());

	Game* game = new Game;
	game->Attach(logs->GetGameLogger());

	Mediator* mediator = new HandleMediator(commander, inputCenter, game);

	game->StartGame();

	delete mediator;
	delete commander;
	delete inputCenter;
	delete game;
	delete logs;
	return 0;
}
