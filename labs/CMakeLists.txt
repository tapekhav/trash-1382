cmake_minimum_required(VERSION 3.23)
project(labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(labs main.cpp Background/Cell.cpp Background/Cell.h Background/CellView.cpp Background/CellView.h Background/Field.cpp Background/Field.h Characters/Player.cpp Characters/Player.h
        Control/Controller.cpp Control/Controller.h Events/Event.h Background/FIeldView.cpp Background/FieldView.h Control/CommandReader.cpp Control/CommandReader.h Control/Mediator.cpp Control/Mediator.h Events/Box.cpp Events/Box.h Events/Heal.cpp Events/Heal.h Events/Enemy.cpp Events/Enemy.h)
