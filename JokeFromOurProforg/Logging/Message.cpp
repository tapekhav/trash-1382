#include "Logging/Message.h"

void Message::IncreaseData(void* data) {
	void** NewData = new void* [mCount + 1];
	for (int idx = 0; idx < mCount; idx++) {
		NewData[idx] = mData[idx];
	}
	NewData[mCount++] = data;
	delete[] mData;
	mData = NewData;
}

Message::~Message() {
	delete[] mData;
	mCount = 0;
}