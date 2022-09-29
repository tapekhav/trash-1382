#include <iostream>
#include "TrapEventJoker.h"
#define DAMAGE 20


TrapEventJoker::~TrapEventJoker(){
    std::cout << "broke\n";
}

void TrapEventJoker::callReaction() {
    std::cout << "Joker's trap\n";
}
