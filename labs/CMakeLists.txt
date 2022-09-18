cmake_minimum_required(VERSION 3.23)
project(labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(labs main.cpp Cell.cpp Cell.h CellView.cpp CellView.h Field.cpp Field.h Player.cpp Player.h
        Controller.cpp Controller.h Event.cpp Event.h FIeldView.cpp FieldView.h CommandReader.cpp CommanderReader.h Mediator.cpp Mediator.h)
