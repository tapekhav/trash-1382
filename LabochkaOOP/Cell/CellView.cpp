//
// Created by corvussharp on 21.09.22.
//

#include "CellView.h"

CellView::CellView(const Cell &c) {
    if (c.get_person_in())
        sym_cell = "🤡";
    else if (dynamic_cast<EventXp *>(c.get_event()) != nullptr)
        sym_cell = "📚";
    else if (dynamic_cast<EventHp *>(c.get_event()) != nullptr)
        sym_cell = "💟";
    else if (dynamic_cast<EventDmg *>(c.get_event()) != nullptr)
        sym_cell = "💪";
    else if (dynamic_cast<EventChangeField *>(c.get_event()) != nullptr)
        sym_cell = "❓";
    else if (dynamic_cast<EventTrap *>(c.get_event()) != nullptr)
        sym_cell = "💩";
    else if (dynamic_cast<EventWin *>(c.get_event()) != nullptr) {
        sym_cell = "🏁";
    } else {
        sym_cell = ' ';
    }
}

std::string CellView::get_cell() const {
    return sym_cell;
};

