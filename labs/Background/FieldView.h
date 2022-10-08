#ifndef LABS_FIELDVIEW_H
#define LABS_FIELDVIEW_H

#include "Field.h"
#include "CellView.h"
#include <vector>

class FieldView {
public:
    explicit FieldView(Field& other);
    void print() const;
private:
    void print_border() const;

    Field field;
};

#endif

