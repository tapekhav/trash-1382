#ifndef LAB2_CELLVIEW_H
#define LAB2_CELLVIEW_H


#include <map>
#include "../Field/Cell/Cell.h"

class CellView{
private:
    std::map<int, char> view = {
            {0, ' '},
            {1, '*'},
            {2, '#'},
            {-1, '?'}
    };

public:
    CellView &operator=(const CellView&);
    char getView(const Cell&) const;
};


#endif