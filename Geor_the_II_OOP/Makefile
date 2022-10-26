all: main.o Cell.o Field.o Player.o CellView.o FieldView.o FacadePlayer.o Observer.o Log.o EventFieldVirtual.o EventMakeBorder.o EventCasing.o EventPlayerVirtual.o EventBonus.o CommandReader.o
	g++ main.o Cell.o Field.o Player.o CellView.o FieldView.o FacadePlayer.o Observer.o Log.o EventFieldVirtual.o EventMakeBorder.o EventCasing.o EventPlayerVirtual.o EventBonus.o CommandReader.o -o OOP_Work
main.o: main.cpp FacadePlayer.h FieldView.h Observer.h Log.h EventCasing.h EventMakeBorder.h EventBonus.h
	g++ -c main.cpp
Cell.o: Cell.cpp CellEvent.h Cell.h
	g++ -c Cell.cpp
Field.o: Field.cpp Field.h Cell.h Observer.h Direction.h
	g++ -c Field.cpp
Player.o: Player.cpp Player.h 
	g++ -c Player.cpp
CellView.o: CellView.cpp CellView.h Cell.h
	g++ -c CellView.cpp
FieldView.o: FieldView.cpp FieldView.h Field.h CellView.h
	g++ -c FieldView.cpp
FacadePlayer.o: FacadePlayer.cpp FacadePlayer.h Player.h Field.h Observer.h FieldView.h CommandReader.h
	g++ -c FacadePlayer.cpp
Observer.o: Observer.cpp Observer.h Log.h Player.h Field.h
	g++ -c Observer.cpp
Log.o: Log.cpp Log.h
	g++ -c Log.cpp
CommandReader.o: CommandReader.cpp CommandReader.h Direction.h
	g++ -c CommandReader.cpp
EventFieldVirtual.o: EventFieldVirtual.cpp EventFieldVirtual.h Field.h CellEvent.h
	g++ -c EventFieldVirtual.cpp
EventMakeBorder.o: EventMakeBorder.cpp EventMakeBorder.h EventFieldVirtual.h
	g++ -c EventMakeBorder.cpp
EventCasing.o: EventCasing.cpp EventCasing.h CellEvent.h
	g++ -c EventCasing.cpp
EventPlayerVirtual.o: EventPlayerVirtual.cpp EventPlayerVirtual.h CellEvent.h Player.h
	g++ -c EventPlayerVirtual.cpp
EventBonus.o: EventBonus.cpp EventBonus.h EventPlayerVirtual.h
	g++ -c EventBonus.cpp