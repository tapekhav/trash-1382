#ifndef COMAND_CONTROLLER_H
#define COMAND_CONTROLLER_H

#include "../Mediator/MediatorObj.h"
#include "../Field/Field.h"
#include "../Input-Output/FieldView.h"
#include "../Support/Enum.h"


class ComandController : public MediatorObj{
private:
    Field CurField;
    FieldView viewer;
public:
    ComandController();

    void setMediator(Mediator* med);

    void ViewField();

    void MovePlayer(Enum::Direction dir);

    void CreateStandartSizeField();

    void CreateCustomField(int heigth, int width);
};

#endif