#ifndef LABS_FIELDVIEW_H
#define LABS_FIELDVIEW_H

#include "Field.h"
#include "CellView.h"

class FieldView : public Observer {
public:
    explicit FieldView(Field* other);
    void update() override;
private:
    void print_border() const;

    Field* field;
};

#endif

