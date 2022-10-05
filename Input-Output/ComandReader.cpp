#include "ComandReader.h"
ComandReader::ComandReader(Mediator* med): MediatorObj(med){}

void ComandReader::Read(){
    std::cin>>MoveSymbol;
    mediator -> ShortCommandNotify(this, MoveSymbol);
}

void ComandReader::ReadStartField(){
    std::cin>>FieldSize.first;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Вы ввели не число! Введите другие значения!\n";
        ReadStartField();
        return;
    }
    std::cin>>FieldSize.second;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Вы ввели не число! Введите другие значения!\n";
        ReadStartField();
        return;
    }
    mediator -> FieldSizeNotify(this, FieldSize);
}

void ComandReader::setMediator(Mediator* med){
        mediator = med;
    }