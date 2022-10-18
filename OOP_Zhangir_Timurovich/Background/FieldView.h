#pragma once

#include <iostream>
#include "Field.h"
#include "CellView.h"
#include "Cell.h"

class FieldView {
public:
    explicit FieldView(Field *other);

    FieldView() = default;

    void print_border() const;


    void show_field();


private:
    Field *field_obj;
};
