#include "Memento.h"

std::string Memento::get_data() const {
    return data;
}

Memento::Memento(const std::string &new_data) {
    data = new_data;
}
