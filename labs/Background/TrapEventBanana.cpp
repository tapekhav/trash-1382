#include <iostream>
#include "TrapEventBanana.h"


TrapEventBanana::~TrapEventBanana(){
    std::cout << "broke\n";
}

void TrapEventBanana::callReaction() {
    std::cout << "You stepped on a banana\n";
}
