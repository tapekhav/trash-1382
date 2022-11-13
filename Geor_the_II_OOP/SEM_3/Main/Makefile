all: main.o Cell.o Field.o Player.o CellView.o FieldView.o FacadePlayer.o Observer.o Log.o EventFieldVirtual.o EventMakeBorder.o EventCasing.o EventPlayerVirtual.o EventBonus.o CommandReaderKeyboard.o SetSetting.o EventCombat.o EventCombatHard.o EventFinal.o LogFile.o LogConsole.o Message.o
	g++ main.o Cell.o Field.o Player.o CellView.o FieldView.o FacadePlayer.o Observer.o Log.o EventFieldVirtual.o EventMakeBorder.o EventCasing.o EventPlayerVirtual.o EventBonus.o CommandReaderKeyboard.o SetSetting.o EventCombat.o EventCombatHard.o EventFinal.o LogFile.o LogConsole.o Message.o -o OOP_Work
main.o: main.cpp ../UserInterface/FacadePlayer.h ../GameBoard/FieldView.h ../Observation/Observer.h ../Logging/Log.h ../Events/EventCasing.h ../Events/FieldEvents/EventMakeBorder.h ../Events/PlayerEvents/EventBonus.h ../Events/PlayerEvents/EventFinal.h ../Logging/LogFile.h ../Logging/LogConsole.h ../CommandReader/CommandReaderKeyboard.h ../CommandReader/SetSetting.h
	g++ -c main.cpp
Cell.o: ../GameBoard/Cell.cpp ../Events/CellEvent.h ../GameBoard/Cell.h
	g++ -c ../GameBoard/Cell.cpp
Field.o: ../GameBoard/Field.cpp ../GameBoard/Field.h ../GameBoard/Cell.h ../CommandReader/CommandOperand.h
	g++ -c ../GameBoard/Field.cpp
Player.o: ../PlayerEssence/Player.cpp ../PlayerEssence/Player.h 
	g++ -c ../PlayerEssence/Player.cpp
CellView.o: ../GameBoard/CellView.cpp ../GameBoard/CellView.h ../GameBoard/Cell.h
	g++ -c ../GameBoard/CellView.cpp
FieldView.o: ../GameBoard/FieldView.cpp ../GameBoard/FieldView.h ../GameBoard/Field.h ../GameBoard/CellView.h
	g++ -c ../GameBoard/FieldView.cpp
FacadePlayer.o: ../UserInterface/FacadePlayer.cpp ../UserInterface/FacadePlayer.h ../PlayerEssence/Player.h ../GameBoard/Field.h ../Observation/Observer.h ../GameBoard/FieldView.h ../CommandReader/CommandReader.h
	g++ -c ../UserInterface/FacadePlayer.cpp
Observer.o: ../Observation/Observer.cpp ../Observation/Observer.h ../Logging/Log.h ../PlayerEssence/Player.h ../GameBoard/Field.h
	g++ -c ../Observation/Observer.cpp
Log.o: ../Logging/Log.cpp ../Logging/Log.h ../Logging/Message.h
	g++ -c ../Logging/Log.cpp
CommandReaderKeyboard.o: ../CommandReader/CommandReaderKeyboard.cpp ../CommandReader/CommandReaderKeyboard.h ../CommandReader/CommandReader.h
	g++ -c ../CommandReader/CommandReaderKeyboard.cpp
SetSetting.o: ../CommandReader/SetSetting.cpp ../CommandReader/SetSetting.h ../Logging/Log.h
	g++ -c ../CommandReader/SetSetting.cpp
Message.o: ../Logging/Message.h ../Logging/Message.cpp ../Logging/MessageLevel.h
	g++ -c ../Logging/Message.cpp
LogFile.o: ../Logging/LogFile.cpp ../Logging/LogFile.h ../Logging/Log.h
	g++ -c ../Logging/LogFile.cpp
LogConsole.o: ../Logging/LogConsole.cpp ../Logging/LogConsole.h ../Logging/Log.h
	g++ -c ../Logging/LogConsole.cpp
EventFieldVirtual.o: ../Events/FieldEvents/EventFieldVirtual.cpp ../Events/FieldEvents/EventFieldVirtual.h ../GameBoard/Field.h ../Events/CellEvent.h
	g++ -c ../Events/FieldEvents/EventFieldVirtual.cpp
EventMakeBorder.o: ../Events/FieldEvents/EventMakeBorder.cpp ../Events/FieldEvents/EventMakeBorder.h ../Events/FieldEvents/EventFieldVirtual.h
	g++ -c ../Events/FieldEvents/EventMakeBorder.cpp
EventCasing.o: ../Events/EventCasing.cpp ../Events/EventCasing.h ../Events/CellEvent.h
	g++ -c ../Events/EventCasing.cpp
EventPlayerVirtual.o: ../Events/PlayerEvents/EventPlayerVirtual.cpp ../Events/PlayerEvents/EventPlayerVirtual.h ../Events/CellEvent.h ../PlayerEssence/Player.h
	g++ -c ../Events/PlayerEvents/EventPlayerVirtual.cpp
EventBonus.o: ../Events/PlayerEvents/EventBonus.cpp ../Events/PlayerEvents/EventBonus.h ../Events/PlayerEvents/EventPlayerVirtual.h
	g++ -c ../Events/PlayerEvents/EventBonus.cpp
EventCombat.o: ../Events/PlayerEvents/EventCombat.cpp ../Events/PlayerEvents/EventCombat.h ../Events/PlayerEvents/EventPlayerVirtual.h
	g++ -c ../Events/PlayerEvents/EventCombat.cpp
EventCombatHard.o: ../Events/PlayerEvents/EventCombatHard.cpp ../Events/PlayerEvents/EventCombatHard.h ../Events/PlayerEvents/EventCombat.h
	g++ -c ../Events/PlayerEvents/EventCombatHard.cpp
EventFinal.o: ../Events/PlayerEvents/EventFinal.cpp ../Events/PlayerEvents/EventFinal.h ../Events/PlayerEvents/EventCombatHard.h
	g++ -c ../Events/PlayerEvents/EventFinal.cpp