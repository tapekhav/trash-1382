#include <iostream>
#include "Field.h"
#include "CellView.h"
#include "FieldView.h"

void FieldView::initialize(Field* field) {
    this->field = field;
    //cellView = CellView();
};


void FieldView::printFieldView() const{
    std::cout << " + ";
    for (int w = 0; w != field->getWidth(); ++w) std::cout<<" - ";
    std::cout << " + \n";

    for(unsigned int h = 0; h != field->getHeight(); ++h){
        std::cout << " | ";
        for(unsigned int w = 0; w != field->getWidth(); ++w) std::cout << " " << cellView.getCellView(field->getCell(field->getHeight()-h-1, w)) << " ";
        std::cout << " | " << '\n';
    }

    std::cout << " + ";
    for (int w = 0; w != field->getWidth(); ++w) std::cout<<" - ";
    std::cout << " + " << '\n';
}

FieldView &FieldView::operator=(const FieldView &other){
    this->field = other.field;
    this->cellView = other.cellView;
    return *this;
}

