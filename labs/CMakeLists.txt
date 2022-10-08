cmake_minimum_required(VERSION 3.23)
project(labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(labs main.cpp Background/Cell.cpp Background/Cell.h Background/CellView.cpp Background/CellView.h Background/Field.cpp Background/Field.h Characters/Player.cpp Characters/Player.h
        Control/Controller.cpp Control/Controller.h Events/ChangePlayer/EventPlayer.h Background/FIeldView.cpp Background/FieldView.h Control/CommandReader.cpp Control/CommandReader.h Control/Mediator.cpp Control/Mediator.h Events/ChangePlayer/Box.cpp Events/ChangePlayer/Box.h Events/ChangePlayer/Heal.cpp Events/ChangePlayer/Heal.h Events/ChangePlayer/Enemy.cpp Events/ChangePlayer/Enemy.h Events/ChangeField/NewLevel.cpp Events/ChangeField/NewLevel.h Events/Rules/EndGame.cpp Events/Rules/EndGame.h Events/Rules/EventRule.h Events/ChangeField/EventField.h)
