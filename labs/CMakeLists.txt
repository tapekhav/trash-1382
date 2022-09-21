cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game main.cpp FieldView.cpp FieldView.h Field.cpp Field.h Cell.cpp Cell.h CellView.cpp CellView.cpp CellView.h Player.cpp Player.h ComandReader.cpp ComandReader.h MediatorObject.cpp MediatorObject.h Mediator.cpp Mediator.h Controller.cpp Controller.h)
