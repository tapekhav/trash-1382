#include <iostream>
#include "Field.h"
#include "CellView.h"
#include "FieldView.h"

void FieldView::print(Field& field) const{
    std::cout << " + ";
    for (int w = 0; w != field.getWidth(); ++w) std::cout<<" - ";
    std::cout << " + \n";

    for(int h = 0; h != field.getHeight(); ++h){
        std::cout << " | ";
        for(int w = 0; w != field.getWidth(); ++w) std::cout << " " << CellView(field.getCell(h, w)).getCellView() << " ";
        std::cout << " | " << '\n';
    }


    std::cout << " + ";
    for (int w = 0; w != field.getWidth(); ++w) std::cout<<" - ";
    std::cout << " + " << '\n';
};