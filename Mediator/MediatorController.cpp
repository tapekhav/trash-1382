#include "MediatorController.h"



void MediatorController::LargeCommandNotify(MediatorObj *obj, std::string Command) {
    if(auto comandR = dynamic_cast<Game *>(obj)){
        if(Command == "CreateStandartField")
            comand_controller -> CreateStandartSizeField();
        else if(Command == "CreateField")
            comand_reader -> ReadStartField();
    }
}


MediatorController::MediatorController(ComandReader* comand_reader, ComandController* comand_controller, Game* game):
    comand_reader(comand_reader), comand_controller(comand_controller), game(game){
        comand_reader->setMediator(this);
        comand_controller->setMediator(this);
        game->setMediator(this);
}

void MediatorController::ShortCommandNotify(MediatorObj *obj, char Command) {
    if (auto comandR = dynamic_cast<ComandReader *>(obj)) {
        switch (Command) {
            case 'w':
                comand_controller->MovePlayer(Enum::UP);
                break;
            case 'a':
                comand_controller->MovePlayer(Enum::LEFT);
                break;
            case 's':
                comand_controller->MovePlayer(Enum::DOWN);
                break;
            case 'd':
                comand_controller->MovePlayer(Enum::RIGHT);
                break;
            case 'Q':
                game->QuitGame();
                break;
        }
    }
}

void MediatorController::FieldSizeNotify(MediatorObj *obj, std::pair<int, int> StartField) {
    if(auto comandR = dynamic_cast<ComandReader*>(obj)){
        comand_controller -> CreateCustomField(StartField.first,StartField.second);
    }
}