

#include "CollapseType.h"

bool CollapseType::get_pass() {
    return this->pass;
}


CollapseType::CollapseType() {
    this->pass = true;
}