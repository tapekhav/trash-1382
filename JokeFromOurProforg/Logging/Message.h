#ifndef SURVIVE_MESSAGE_H
#define SURVIVE_MESSAGE_H

#include "Enums.h"

class Message {
public:
	Message(EnumClass::Log type) : mType(type), mData(nullptr), mCount(0) {}

	void IncreaseData(void* data);

	int GetCount() const { return mCount; }
	void* GetData(int idx) const { return mData[idx]; }
	EnumClass::Log GetLog() const { return mType; }

	~Message();

private:
	void** mData;
	int mCount;
	EnumClass::Log mType;
};

#endif //SURVIVE_MESSAGE_H