#include "FieldView.h"

FieldView::FieldView(Field& other) : field(other) {}

void FieldView::print() const {
    std::cout << "Текущее состояние поля:\n";
    print_border();
    for (int i = 0; i != field.get_height(); ++i) {
        std::cout << "|";
        for (int j = 0; j != field.get_width(); ++j) {
            std::cout << CellView(field.get_cur_cell(j, i)).get_cell() << "  ";
        }
        std::cout << " |\n";
    }
    print_border();
}

void FieldView::print_border() const {
    for (size_t i = 0; i != field.get_width() + 1; ++i)
        std::cout << " _ ";
    std::cout << "\n";
}
