#include "ComandController.h"

ComandController::ComandController() {}

void ComandController::setMediator(Mediator* med){
    mediator = med;
}

void ComandController::ViewField(){
    viewer.DrawField(CurField);
}

void ComandController::MovePlayer(Enum::Direction dir){
    CurField.PlayersMove(dir);
}

void ComandController::CreateStandartSizeField(){
    CurField = Field();
}

void ComandController::CreateCustomField(int heigth, int width){
    CurField = Field(heigth,width);
}