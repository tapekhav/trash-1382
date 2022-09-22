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
		DoCmd();
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

void HandleMediator::DoCmd() const {
	mCommander->ShowField();
	mCommandReader->Read();
	switch (mApproval)
	{
	case 'd':
		mCommander->PlayerGo(RIGHT);
		break;
	case 'w':
		mCommander->PlayerGo(DOWN);
		break;
	case 'a':
		mCommander->PlayerGo(LEFT);
		break;
	case 's':
		mCommander->PlayerGo(UP);
		break;
	case 'q':
		mCommander->SetGameProgress(false);
		return;
	}
}