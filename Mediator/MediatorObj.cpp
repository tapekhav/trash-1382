#include "MediatorObj.h"

MediatorObj::MediatorObj(Mediator* med) : mediator(med){}

void MediatorObj::setMediator(Mediator* med){
    mediator = med; 
}