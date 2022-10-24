cmake_minimum_required(VERSION 3.23)
project(trash_1382)

set(CMAKE_CXX_STANDARD 14)

include_directories(Background)
include_directories(Characters)
include_directories(Control)
include_directories(Logging)
include_directories(Events)
include_directories(Events/ChangeField)
include_directories(Events/ChangePlayer)

add_executable(trash_1382
        Background/Cell.cpp
        Background/Cell.h
        Background/CellView.cpp
        Background/CellView.h
        Background/Field.cpp
        Background/Field.h
        Background/FIeldView.cpp
        Background/FieldView.h
        Characters/Player.cpp
        Characters/Player.h
        Characters/PlayerView.cpp
        Characters/PlayerView.h
        Logging/Observable.cpp
        Logging/Observable.h
        Logging/Observer.h
        Control/CommandReader.cpp
        Control/CommandReader.h
        Control/Controller.cpp
        Control/Controller.h
        Control/Mediator.cpp
        Control/Mediator.h
        Events/ChangeField/EventField.h
        Events/ChangeField/SetWalls.cpp
        Events/ChangeField/SetWalls.h
        Events/ChangePlayer/Box.cpp
        Events/ChangePlayer/Box.h
        Events/ChangePlayer/EventPlayer.h
        Events/ChangePlayer/Heal.cpp
        Events/ChangePlayer/Heal.h
        Events/ChangePlayer/Key.cpp
        Events/ChangePlayer/Key.h
        Events/ChangePlayer/Trap.cpp
        Events/ChangePlayer/Trap.h
        Events/Event.h main.cpp Events/EventCreator.cpp Events/EventCreator.h Events/ChangeField/DelWalls.cpp Events/ChangeField/DelWalls.h Logging/Logger/Logger.h Control/GameStatus.cpp Control/GameStatus.h Logging/Messages/Message.h Logging/Logger/ConsoleLog.cpp Logging/Logger/ConsoleLog.h Logging/Logger/FileLog.cpp Logging/Logger/FileLog.h Logging/Messages/GameMsg.cpp Logging/Messages/GameMsg.h Logging/Messages/EventMsg.cpp Logging/Messages/EventMsg.h Logging/Messages/InputMsg.cpp Logging/Messages/InputMsg.h Logging/LogType/GameLog.cpp Logging/LogType/GameLog.h Logging/LogType/LogType.h)
