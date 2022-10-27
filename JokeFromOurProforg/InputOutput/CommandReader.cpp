#include "InputOutput/CommandReader.h"

void CommandReader::Start() {
    Help(false);
    std::cout << "Do you want to enter a size of map yourself? [Y/N]\n";
    std::cin >> mApproval;
    mMediator->CharMsg(mApproval);

}

void CommandReader::IncorrectInput() {
    std::cout << "Incorrect command! Please, check the correct format of the enter!\n";
    CreateMessage(EnumClass::LOG_ERROR_INCORRECT_INPUT, &mApproval);
    std::cin >> mApproval;
    mMediator->CharMsg(mApproval);
}

void CommandReader::ReadWidthAndHeight() {
    std::cout << "The size of the map must be in range from 3 to 20\n";
    std::cout << "If you enter an incorrect output, the values will move to the rigth range\n";
    std::cout << "Enter a size for the map." << std::endl << "Width: ";
    std::cin >> mSize.first;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "This input is incorrect!\nEnter number: ";
        std::cin >> mSize.first;
    }

    std::cout << "\nHeight: ";
    std::cin >> mSize.second;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "This input is incorrect!\nEnter number: ";
        std::cin >> mSize.second;
    }
    CreateMessage(EnumClass::LOG_ERROR_FIELD_SIZE, &mSize.first, &mSize.second);
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

void CommandReader::Help(bool type) const {
    std::cout << "The Helper to navigate in this game!" << std::endl;
    std::cout << "At this moment the following commands are available:" << std::endl;
    std::cout << "\th -- The program will repeat this helping message one more time." << std::endl;
    std::cout << "\tw -- The player will go up." << std::endl;
    std::cout << "\ta -- The player will go left." << std::endl;
    std::cout << "\ts -- The player will go down." << std::endl;
    std::cout << "\td -- The player will go right." << std::endl;
    std::cout << "\tq -- The program will finish working." << std::endl;

    if (type) {
        char c;
        std::cout << "Enter any symbol to continue: ";
        std::cin >> c;
    }
}

void CommandReader::DefeatMsg() const {
    std::cout << "---DEFEAT---" << std::endl;
    std::cout << "Unfortunately, you're dead!" << std::endl;
}

void CommandReader::VictoryMsg() const {
    std::cout << "---VICTORY---" << std::endl;
    std::cout << "You survived. You won." << std::endl;
}

void CommandReader::CreateMessage(EnumClass::Log type, char* val) {
    Message* msg = new Message(type);
    msg->IncreaseData(val);
    Notify(msg);
    delete msg;
}

void CommandReader::CreateMessage(EnumClass::Log type, int* pos1, int* pos2) {
    if (EnumClass::MIN_SIZE <= *pos1 && *pos1 <= EnumClass::MAX_SIZE &&
        EnumClass::MIN_SIZE <= *pos2 && *pos2 <= EnumClass::MAX_SIZE)
        return;
    Message* msg = new Message(type);
    msg->IncreaseData(pos1);
    msg->IncreaseData(pos2);
    Notify(msg);
    delete msg;
}