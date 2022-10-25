//
// Created by corvussharp on 21.09.22.
//

#ifndef UNTITLED48_FIELDVIEW_H
#define UNTITLED48_FIELDVIEW_H
#include "Field.h"
#include "iostream"
#include "../Cell/CellView.h"
class FieldView{
private:
    Field field;

public:
    explicit FieldView(Field& other);
    void print() const;
    void print_bord() const;
};

#endif //UNTITLED48_FIELDVIEW_H
