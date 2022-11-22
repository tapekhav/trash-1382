#ifndef LABS_FIELDGENERATOR_H
#define LABS_FIELDGENERATOR_H

#include "Field.h"

template<class... Rules>
class FieldGenerator {
public:
    Field* fill(int width, int height) {
        auto* field = new Field(width, height);
        (Rules()(*field),...);

        return field;
    }
};


#endif //LABS_FIELDGENERATOR_H
