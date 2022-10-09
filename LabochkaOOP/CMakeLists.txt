cmake_minimum_required(VERSION 3.23)
project(LabochkaOOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(LabochkaOOP main.cpp EventsPerson/EventPerson.cpp EventsPerson/EventPerson.h
        EventsPerson/EventXp.cpp EventsPerson/EventXp.h EventsPerson/EventHp.cpp EventsPerson/EventHp.h EventsPerson/EventDmg.cpp EventsPerson/EventDmg.h
        Cell/Cell.cpp Cell/Cell.h Cell/CellView.cpp Cell/CellView.h
        Persons/Person.cpp Persons/Person.h Field/Field.cpp Field/Field.h Field/FieldView.cpp Field/FieldView.h Commands/CommandReader.cpp
        Commands/CommandReader.h Commands/Controller.cpp Commands/Controller.h Commands/Mediator.cpp Commands/Mediator.h
        EventsField/EventField.cpp EventsField/EventField.h Enemy/Enemy.cpp Enemy/Enemy.h)
