cmake_minimum_required(VERSION 3.23)
project(LabochkaOOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(LabochkaOOP main.cpp Events/EventsPerson/EventPerson.h
        Events/EventsPerson/EventXp.cpp Events/EventsPerson/EventXp.h Events/EventsPerson/EventHp.cpp Events/EventsPerson/EventHp.h Events/EventsPerson/EventDmg.cpp Events/EventsPerson/EventDmg.h
        Cell/Cell.cpp Cell/Cell.h Cell/CellView.cpp Cell/CellView.h
        Persons/Person.cpp Persons/Person.h Field/Field.cpp Field/Field.h Field/FieldView.cpp Field/FieldView.h
        Commands/Controller.cpp Commands/Controller.h Commands/Mediator.cpp Commands/Mediator.h
        Events/EventsField/EventField.h  Events/Event.h Events/EventsField/EventWin.cpp Events/EventsField/EventWin.h Events/EventsField/EventChangeField.cpp Events/EventsField/EventChangeField.h Events/EventsPerson/EventTrap.cpp Events/EventsPerson/EventTrap.h LOG/Logs/Observer.h
        LOG/LogsInfo/LogOutInfo.cpp LOG/LogsInfo/LogOutInfo.h LOG/LogsInfo/Structs.h LOG/Logging/Logger.cpp LOG/Logging/Logger.h LOG/Logging/Message.h LOG/Logging/Message.cpp LOG/Logs/LogsLvlErrors.cpp LOG/Logs/LogsLvlErrors.h LOG/Logs/LogsLvlGame.cpp LOG/Logs/LogsLvlGame.h LOG/Logs/LogsStatus.cpp LOG/Logs/LogsStatus.h LOG/OutPut/Output.h LOG/OutPut/FileOut.h LOG/OutPut/FileOut.cpp LOG/OutPut/ConsoleOut.cpp LOG/OutPut/ConsoleOut.h LOG/Logs/Subject.cpp INPUT/ControlFile.cpp INPUT/ControlFile.h INPUT/ControlConfig.h Commands/CommandRead.h Commands/GameSettings.cpp Commands/GameSettings.h Commands/ConsoleReader.cpp Commands/ConsoleReader.h Commands/ConsoleGameSetings.cpp Commands/ConsoleGameSetings.h)
