#include "Processing/HandleMediator.h"


void HandleMediator::Notify(EnumClass::Action activity) {
	switch (activity)
	{
	case EnumClass::FIELD_SIZE:
		mCommander->SetFieldSize(mInputCenter->GetFieldSize());
		
	case EnumClass::DO_CMD:
		mCommander->ShowField();
		switch (mInputCenter->GetCommand())
		{
		case EnumClass::RIGHT:
			mCommander->PlayerGo(EnumClass::RIGHT);
			break;
		case EnumClass::UP:
			mCommander->PlayerGo(EnumClass::UP);
			break;
		case EnumClass::LEFT:
			mCommander->PlayerGo(EnumClass::LEFT);
			break;
		case EnumClass::DOWN:
			mCommander->PlayerGo(EnumClass::DOWN);
			break;
		case EnumClass::QUIT:
			mGame->SetGameProgress(false);
			break;
		}
		break;
	case EnumClass::DEFEAT:
		mGame->SetGameProgress(false);
		break;
	case EnumClass::VICTORY:
		mGame->SetGameProgress(false);
		break;
	case EnumClass::MOVE_COUNT:
		mCommander->SetMove(mGame->GetMove());
		break;
	}
	

}
