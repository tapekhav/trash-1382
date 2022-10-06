//
// Created by corvussharp on 21.09.22.
//

#include "FieldView.h"
void FieldView::print_bord() const{
    for (int i = 0; i != field.get_width()+1; ++i) {
        std::cout << " * ";
    }
    std::cout<<std::endl;
}

  FieldView::FieldView(Field& other): field(other){
    };
    void FieldView::print() const{
        std::cout << "Текущее состояние поля:\n";
        print_bord();
        for (int i = 0; i != field.get_height(); ++i) {
            std::cout << "*";
            for (int j = 0; j != field.get_width(); ++j)
                std::cout << CellView(field.get_field().at(i).at(j)).get_cell() << "  ";
            std::cout << " *\n";
        }
        print_bord();
    }



