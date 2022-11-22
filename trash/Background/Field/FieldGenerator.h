#ifndef LABS_FIELDGENERATOR_H
#define LABS_FIELDGENERATOR_H

#include "Field.h"

template<class... Rules>
class FieldGenerator {
public:
    Field fill(int width, int height) {
        Field field(width, height);
        (Rules(field),...);

        return field;
    }
};


#endif //LABS_FIELDGENERATOR_H
