#ifndef LABS_FIELDVIEW_H
#define LABS_FIELDVIEW_H

#include "Field.h"
#include "CellView.h"

class FieldView {
public:
    explicit FieldView(Field*);
    void update();
private:
    void print_border() const;

    Field* field;
};

#endif

