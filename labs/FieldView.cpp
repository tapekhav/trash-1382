#include <iostream>
#include "Field.h"
#include "CellView.h"
#include "FieldView.h"

void FieldView::print(const Field& field) const{
    std::cout << " + ";
    for (int w = 0; w != field.getWidth(); ++w) std::cout<<" - ";
    std::cout << " + \n";

    for(unsigned int h = 0; h != field.getHeight(); ++h){
        std::cout << " | ";
        for(unsigned int w = 0; w != field.getWidth(); ++w) std::cout << " " << CellView(field.getCell(field.getHeight()-h-1, w)).getCellView() << " ";
        std::cout << " | " << '\n';
    }

    std::cout << " + ";
    for (int w = 0; w != field.getWidth(); ++w) std::cout<<" - ";
    std::cout << " + " << '\n';
};