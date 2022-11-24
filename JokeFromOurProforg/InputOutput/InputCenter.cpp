#include "InputOutput/InputCenter.h"

InputCenter::InputCenter() {
	mConfig = new Config;
	mInputData = new CommandLineInput;
	mCommunicator = new Communicator;
}

std::pair<int, int> InputCenter::GetFieldSize() const {
	mCommunicator->Greeting();
	bool rightSym = true, flag;
	std::pair<int, int> userSize;

	while (rightSym) {
		switch (mConfig->GetCommand(mInputData->GetCommand()))
		{
		case EnumClass::YES:
			rightSym = false;
			flag = true;
			mCommunicator->SetFieldSize();
			userSize = mInputData->GetFieldSize();
			if (EnumClass::MIN_SIZE > userSize.first || EnumClass::MAX_SIZE < userSize.first) {
				flag = false;
				if (userSize.first - EnumClass::MIN_SIZE < 0)
					userSize.first = EnumClass::MIN_SIZE;
				else
					userSize.first = EnumClass::MAX_SIZE;
			}
			if (EnumClass::MIN_SIZE > userSize.second || EnumClass::MAX_SIZE < userSize.second) {
				flag = false;
				if (userSize.second - EnumClass::MIN_SIZE < 0)
					userSize.second = EnumClass::MIN_SIZE;
				else
					userSize.second = EnumClass::MAX_SIZE;
			}
			system("cls");
			if (!flag)
				mCommunicator->SetStandartSize();
			return userSize;
		case EnumClass::NO:
			rightSym = false;
			userSize.first = EnumClass::STANDARD_SIZE;
			userSize.second = EnumClass::STANDARD_SIZE;
			system("cls");
			return userSize;
		default:
			mCommunicator->WrongAnswer();
			break;
		}
	}

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