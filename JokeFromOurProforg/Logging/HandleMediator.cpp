#include "Logging/HandleMediator.h"


void HandleMediator::Notify(EnumClass::Action activity) {
	switch (activity)
	{
	case EnumClass::FIELD_SIZE:
		mCommandReader->Start();
		while (mApproval != 'Y' && mApproval != 'N')
			mCommandReader->IncorrectInput();
		if (mApproval == 'Y') {
			mCommandReader->ReadWidthAndHeight();
			if (mSize.first < EnumClass::MIN_SIZE) {
				mSize.first = EnumClass::MIN_SIZE;
			}
			else if (mSize.first > EnumClass::MAX_SIZE) {
				mSize.first = EnumClass::MAX_SIZE;
			}
			if (mSize.second < EnumClass::MIN_SIZE) {
				mSize.second = EnumClass::MIN_SIZE;
			}
			else if (mSize.second > EnumClass::MAX_SIZE) {
				mSize.second = EnumClass::MAX_SIZE;
			}
			mCommander->SetFieldSize(mSize.first, mSize.second);
		}
		else {
			mCommander->SetFieldSize(EnumClass::STANDARD_SIZE, EnumClass::STANDARD_SIZE);
		}
		mGame->SetGameProgress(true);
		break;
	case EnumClass::DO_CMD:
		while (!DoCmd()) {
			mCommandReader->Help(false);
			mCommandReader->IncorrectInput();
		}
		break;
	case EnumClass::FINISH:
		mCommandReader->GoodBye();
	}
}

void HandleMediator::CharMsg(char& cmd) {
	mApproval = cmd;
}

void HandleMediator::PairMsg(std::pair<int, int>& couple) {
	mSize = couple;
}

bool HandleMediator::DoCmd() const {
	mCommander->ShowField();
	mCommandReader->Read();
	switch (mApproval)
	{
	case 'd':
		mCommander->PlayerGo(EnumClass::RIGHT);
		break;
	case 'w':
		mCommander->PlayerGo(EnumClass::UP);
		break;
	case 'a':
		mCommander->PlayerGo(EnumClass::LEFT);
		break;
	case 's':
		mCommander->PlayerGo(EnumClass::DOWN);
		break;
	case 'q':
		mGame->SetGameProgress(false);
		break;
	case 'h':
		mCommandReader->Help(true);
		break;
	default:
		mCommandReader->IncorrectInput();
	}
	return true;
}