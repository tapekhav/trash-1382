//
// Created by corvussharp on 21.09.22.
//

#include "CellView.h"

    CellView::CellView(const Cell& sym){
        switch (sym.get_obj()) {
            case Cell::STANDARD:
                sym_cell = ' ';
                break;
            case Cell::BLOCK:
                sym_cell = '!';
                break;
            case Cell::HP:
                sym_cell = 'H';
                break;
            case Cell::PERSON:
                sym_cell = 'Y';
                break;
            case Cell::BOX:
                sym_cell = 'B';
                break;
            case Cell::DMG:
                sym_cell = 'D';
                break;
            case Cell::CHANGEMAP:
                sym_cell = 'X';
                break;
            default:
                sym_cell = '?';
                break;
        }

    }
    char CellView::get_cell()const{
        return sym_cell;
    };

