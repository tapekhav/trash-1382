#include "FieldView.h"

FieldView::FieldView(Field& other) : field(other) {}

void FieldView::print() const {
    if(field.get_width() == 0 || field.get_height() == 0)
        return;
    print_border();
    for (size_t i = 0; i != field.get_height(); ++i) {
        std::cout << "|";
        for (size_t j = 0; j != field.get_width(); ++j)
            std::cout << CellView(field.get_field().at(i).at(j)).get_cell() << "  ";
        std::cout << " |\n";
    }
    print_border();
}

void FieldView::print_border() const {
    for (size_t i = 0; i != field.get_width() + 1; ++i)
        std::cout << " _ ";
    std::cout << "\n";
}
