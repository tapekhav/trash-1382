#ifndef GAME_FIELDVIEW_H
#define GAME_FIELDVIEW_H

#include "Field.h"
#include "../Cell/CellView.h"
#include "../../Runtime/Observer.h"
#include "../../Runtime/Model.h"

class FieldView: public Observer{
public:
    FieldView() = default;
    FieldView(Model *model);
    void update() final;
private:
    void printFieldView(const Field*) const;
    CellView cellView;
    Model* model;
};


#endif
