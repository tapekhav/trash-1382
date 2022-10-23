# CMakeList.txt: проект CMake для Survival; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
include_directories(.)
add_executable (Survival "Main.cpp" "Main.h" "Field/Field.h" "Field/Field.cpp" "Player/Player.h" "Player/Player.cpp" "Event/Event.h" "Processing/Mediator.h"  "Processing/HandleMediator.h" "Processing/Handle.h" "Processing/HandleMediator.cpp" "InputOutput/CommandReader.h" "InputOutput/CommandReader.cpp" "InputOutput/FieldViewer.h" "InputOutput/FieldViewer.cpp" "Processing/Commander.h" "Processing/Commander.cpp" "Processing/Game.h" "Processing/Game.cpp" "Field/Cell.h" "Field/Cell.cpp"   "InputOutput/CellView.h" "InputOutput/CellView.cpp" "Enums.h" "InputOutput/PlayerView.h" "InputOutput/PlayerView.cpp" "Event/EventManager.h"  "Event/Manager.h" "Event/EventManager.cpp"  "Event/Bush/Bush.h" "Event/Factory/Factory.h" "Event/Factory/BerryFactory.h" "Event/Bush/BerryBush.h"  "Event/Bush/WolfBush.h" "Event/Factory/WolfFactory.h" "Event/Bush/BerryBush.cpp" "Event/Bush/WolfBush.cpp" "Event/Bush/BearBush.h" "Event/Bush/BearBush.cpp" "Event/Factory/BearFactory.h" "Event/Bush/RabbitBush.h" "Event/Bush/RabbitBush.cpp" "Event/Factory/RabbitFactory.h" "Event/Cave/Cave.h"   "Event/Cave/WaterCave.h" "Event/Cave/WaterCave.cpp" "Event/Factory/WaterFactory.h" "Event/Cave/TeleportCave.h" "Event/Cave/TeleportCave.cpp" "Event/Factory/TeleportFactory.h" "Event/Cave/SaintWaterCave.h" "Event/Cave/SaintWaterCave.cpp" "Event/Factory/SaintWaterFactory.h"    "Event/Cave/EarthQuakeCave.h" "Event/Factory/EarthQuakeFactory.h" "Event/Cave/EarthQuakeCave.cpp" "Logging/Message.h"  "Logging/Observer.h" "Logging/Subject.h"    )
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Survival PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
