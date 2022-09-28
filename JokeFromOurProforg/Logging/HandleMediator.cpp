#include "Logging/HandleMediator.h"


void HandleMediator::Notify(Action activity) {
	switch (activity)
	{
	case FIELD_SIZE:
		mCommandReader->Start();
		while (mApproval != 'Y' && mApproval != 'N')
			mCommandReader->IncorrectInput();
		if (mApproval == 'Y') {
			mCommandReader->ReadWidthAndHeight();
			if (mSize.first < 1)
				mSize.first = 1;
			else if (mSize.first > MAX_SIZE)
				mSize.first = MAX_SIZE;
			if (mSize.second < 1)
				mSize.second = 1;
			else if (mSize.second > MAX_SIZE)
				mSize.second = MAX_SIZE;
			mCommander->SetFieldSize(mSize.first, mSize.second);
		}
		else {
			mCommander->SetStandardSizeField();
		}
		break;
	case GAME_PROGRESS:
		mGame->SetGameProgress(mCommander->GetGameProgress());
		break;
	case DO_CMD:
		while (!DoCmd()) {
			mCommandReader->Help(false);
			mCommandReader->IncorrectInput();
		}
		break;
	case FINISH:
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
		mCommander->PlayerGo(RIGHT);
		break;
	case 'w':
		mCommander->PlayerGo(UP);
		break;
	case 'a':
		mCommander->PlayerGo(LEFT);
		break;
	case 's':
		mCommander->PlayerGo(DOWN);
		break;
	case 'q':
		mCommander->SetGameProgress(false);
		break;
	case 'h':
		mCommandReader->Help(true);
		break;
	default:
		return false;
	}
	return true;
}