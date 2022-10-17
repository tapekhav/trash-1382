#ifndef MEDIATOR_CONTROLLER_H
#define MEDIATOR_CONTROLLER_H

#include "MediatorObj.h"
#include "../Input-Output/ComandReader.h"
#include "../GameControl/ComandController.h"
#include "../GameControl/Game.h"
#include "../Support/Enum.h"


class MediatorController : public Mediator {
private:
    ComandReader* comand_reader;
    ComandController* comand_controller;
    Game* game;
public:
    MediatorController(ComandReader* comand_reader, ComandController* comand_controller, Game* game);
    
    void ShortCommandNotify(MediatorObj* obj, char Command) override;

    void FieldSizeNotify(MediatorObj* obj, std::pair<int, int> StartField) override;

    void LargeCommandNotify(MediatorObj* obj, std::string Command) override;

};
#endif