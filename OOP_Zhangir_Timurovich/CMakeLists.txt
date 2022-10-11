cmake_minimum_required(VERSION 3.16)
project(OOP_Zhangir_Timurovich)

set(CMAKE_CXX_STANDARD 14)

include_directories(Background)
include_directories(Characters)
include_directories(Control)
include_directories(Events)
include_directories(CellTypes)

add_executable(OOP_Zhangir_Timurovich
        Background/Cell.cpp
        Background/Cell.h
        Background/CellView.cpp
        Background/CellView.h
        Background/Field.cpp
        Background/Field.h
        Background/FieldView.cpp
        Background/FieldView.h
        Characters/Player.cpp
        Characters/Player.h
        Control/CommandReader.cpp
        Control/CommandReader.h
        Control/Controller.cpp
        Control/Controller.h
        Control/Mediator.cpp
        Control/Mediator.h
        Events/Event.cpp
        Events/Event.h
        main.cpp CellTypes/CellType.h Characters/PlayerView.cpp Characters/PlayerView.h Events/FieldEvents/FieldEvent.h Events/PlayerEvents/PlayerEvent.h Events/PlayerEvents/GetCoin.cpp Events/PlayerEvents/GetCoin.h Events/PlayerEvents/Heal.cpp Events/PlayerEvents/Heal.h Events/PlayerEvents/Enemy.cpp Events/PlayerEvents/Enemy.h CellTypes/CellType.cpp)
