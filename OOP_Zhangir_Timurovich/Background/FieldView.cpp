
#include "FieldView.h"
#include <iostream>
#include <cstdlib>

FieldView::FieldView(Field *other) {
    this->field_obj = other;
}

void FieldView::show_field() {
    system("clear");
    std::vector<int> sizes = this->field_obj->get_size();
    for (int i = 0; i <= sizes[0]; i++) {
        std::cout <<" - ";
    }
    std::cout << '\n';
    for (int y = 0; y < sizes[1]; y++) {
        std::cout << " | ";
        for (int x = 1; x < sizes[0]; x++) {
            if (this->field_obj->get_player_x() == x && this->field_obj->get_player_y() == y) {
                std::cout << " p ";
                continue;
            }
            CellView cell_view(this->field_obj->get_cell(x, y));
            char sym = cell_view.get_view();
            std::cout << ' ' << sym << ' ';
        }
        std::cout << " | \n";
    }
    for (int i = 0; i <= sizes[0]; i++) {
        std::cout <<" - ";
    }
    std::cout << '\n';
}
