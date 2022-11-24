#ifndef SURVIVE_INPUTCENTER_H
#define SURVIVE_INPUTCENTER_H

#include "Processing/Handle.h"
#include "Logging/Subject.h"
#include "Config/Config.h"
#include "InputOutput/Communicator.h"
#include "InputOutput/CommandLineInput.h"

class InputCenter : public Handle, public Subject {
public:
	InputCenter();

	std::pair<int, int> GetFieldSize() const;
	EnumClass::Commands GetCommand() const;

	~InputCenter();
private:
	IConfig* mConfig;
	InputData* mInputData;
	Communicator* mCommunicator;
};

#endif //SURVIVE_INPUTCENTER_H