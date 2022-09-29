#ifndef GAME_FIELDVIEW_H
#define GAME_FIELDVIEW_H

#include "Field.h"
#include "CellView.h"

class FieldView {
public:
    void initialize(Field* field);
    void printFieldView() const;
    FieldView &operator=(const FieldView &other);
private:
    Field* field;
    CellView cellView;
};


#endif
