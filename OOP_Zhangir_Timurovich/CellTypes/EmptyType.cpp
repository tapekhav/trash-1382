
#include "EmptyType.h"

bool EmptyType::get_pass() {
    return this->pass;
}



EmptyType::EmptyType() {
    this->pass = true;
}