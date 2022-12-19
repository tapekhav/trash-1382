#include "InputOutput/InputCenter.h"

InputCenter::InputCenter() {
	mConfig = new Config;
	mInputData = new CommandLineInput;
	mCommunicator = new Communicator;
}

int InputCenter::GetLevel() const {
	mCommunicator->Greeting();
	return mInputData->GetLevel();

}

EnumClass::Commands InputCenter::GetCommand() const {
	EnumClass::Commands cmd = mConfig->GetCommand(mInputData->GetCommand());
	while (cmd == EnumClass::UNKNOWN) {
		mCommunicator->WrongAnswer();
		cmd = mConfig->GetCommand(mInputData->GetCommand());
	}
	system("cls");
	return cmd;
}

InputCenter::~InputCenter() {
	delete mConfig;
	delete mInputData;
	delete mCommunicator;
}