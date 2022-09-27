
#include "FieldView.h"
#include <iostream>
#include <cstdlib>

FieldView::FieldView(Field *other) {
    this->field_obj = other;
}

void FieldView::show_field() {
    system("clear");
    std::vector<int> sizes = this->field_obj->get_size();
    std::vector<std::vector<Cell>> field = field_obj->get_field();
    for (int y = 0; y < sizes[1]; y++) {
        std::cout << '\n';
        for (int x = 0; x < sizes[0]; x++) {
            CellView cell_view(field.at(y).at(x));
            char sym = cell_view.get_cell();
            std::cout << ' ' << sym << ' ';
        }
    }
    std::cout << '\n';
}
