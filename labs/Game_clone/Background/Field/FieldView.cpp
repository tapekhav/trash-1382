#include <iostream>
#include "Field.h"
#include "../Cell/CellView.h"
#include "FieldView.h"


FieldView::FieldView(Model *model): model(model) {
    model->setObserver(this);
}

void FieldView::printFieldView(const Field* field) const{
    std::cout << "In print View " <<field->getFieldSize().first << '\t' << field->getFieldSize().second << '\n';


    std::cout << " + ";
    for (int w = 0; w != field->getFieldSize().first; ++w) std::cout<<" - ";
    std::cout << " + \n";

    for(unsigned int h = 0; h != field->getFieldSize().second; ++h){
        std::cout << " | ";
        for(unsigned int w = 0; w != field->getFieldSize().first; ++w) std::cout << " " << cellView.getView(field->getCell(field->getFieldSize().second-h-1, w)) << " ";
        std::cout << " | " << '\n';
    }

    std::cout << " + ";
    for (int w = 0; w != field->getFieldSize().first; ++w) std::cout<<" - ";
    std::cout << " + " << '\n';
}

void FieldView::update() {
    printFieldView(model->getField());
};
