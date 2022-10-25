cmake_minimum_required(VERSION 3.23)
project(LabochkaOOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(LabochkaOOP main.cpp Events/EventsPerson/EventPerson.cpp Events/EventsPerson/EventPerson.h
        Events/EventsPerson/EventXp.cpp Events/EventsPerson/EventXp.h Events/EventsPerson/EventHp.cpp Events/EventsPerson/EventHp.h Events/EventsPerson/EventDmg.cpp Events/EventsPerson/EventDmg.h
        Cell/Cell.cpp Cell/Cell.h Cell/CellView.cpp Cell/CellView.h
        Persons/Person.cpp Persons/Person.h Field/Field.cpp Field/Field.h Field/FieldView.cpp Field/FieldView.h Commands/CommandReader.cpp
        Commands/CommandReader.h Commands/Controller.cpp Commands/Controller.h Commands/Mediator.cpp Commands/Mediator.h
        Events/EventsField/EventField.cpp Events/EventsField/EventField.h Enemy/Enemy.cpp Enemy/Enemy.h Events/Events.h Events/EventsField/EventWin.cpp Events/EventsField/EventWin.h Events/EventsField/EventChangeField.cpp Events/EventsField/EventChangeField.h Events/EventsPerson/EventTrap.cpp Events/EventsPerson/EventTrap.h)
