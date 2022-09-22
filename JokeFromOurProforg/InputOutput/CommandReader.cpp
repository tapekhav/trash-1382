#include "InputOutput/CommandReader.h"

void CommandReader::Start() {
    std::cout << "Do you want to enter a size of map yourself? [Y/N]\n";
    std::cin >> mApproval;
    mMediator->CharMsg(mApproval);

}

void CommandReader::IncorrectInput() {
    std::cout << "Incorrect command! Please, check the correct format of the enter!\n";
    std::cin >> mApproval;
    mMediator->CharMsg(mApproval);
}

void CommandReader::ReadWidthAndHeight() {
    std::cout << "Enter a size for the map." << std::endl << "Width: ";
    std::cin >> mSize.first;
    std::cout << "\nHeight: ";
    std::cin >> mSize.second;
    std::cout << std::endl;
    mMediator->PairMsg(mSize);
}

void CommandReader::Read() {
    std::cout << "Enter the activity: ";
    std::cin >> mApproval;
    std::cout << std::endl;
    mMediator->CharMsg(mApproval);
}

void CommandReader::GoodBye() const {
    std::cout << "Thank you for the test! See you later :)" << std::endl;
}