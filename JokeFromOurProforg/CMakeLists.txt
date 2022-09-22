# CMakeList.txt: проект CMake для Survival; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
include_directories(.)
add_executable (Survival "Main.cpp" "Main.h" "Field/Field.h" "Field/Field.cpp" "Player/Player.h" "Player/Player.cpp" "Event/Event.h" "Logging/Mediator.h"  "Logging/HandleMediator.h" "Logging/Handle.h" "Logging/HandleMediator.cpp" "InputOutput/CommandReader.h" "InputOutput/CommandReader.cpp" "InputOutput/FieldViewer.h" "InputOutput/FieldViewer.cpp" "Logging/Commander.h" "Logging/Commander.cpp" "Logging/Game.h" "Logging/Game.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Survival PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
