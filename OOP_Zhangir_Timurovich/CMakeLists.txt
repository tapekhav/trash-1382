cmake_minimum_required(VERSION 3.16)
project(OOP_roma)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_roma main.cpp Background/Cell.cpp Background/Cell.h Background/CellView.cpp
        Background/CellView.h Background/Field.cpp Background/Field.h Background/FieldView.cpp
        Background/FieldView.h Background/FieldGeneration/FieldGenerator.h
        Background/FieldGeneration/Rules/CoinSetRule.h
        Background/FieldGeneration/Rules/CollapseSetRule.h
        Background/FieldGeneration/Rules/EnemySpawnRule.h
        Background/FieldGeneration/Rules/FieldCreaseRule.h
        Background/FieldGeneration/Rules/HealSetRule.h
        Background/FieldGeneration/Rules/PlayerSpawnRule.h
        Background/FieldGeneration/Rules/WallSetRule.h Characters/Player.cpp Characters/Player.h
        Characters/PlayerView.cpp Characters/PlayerView.h Control/ControlConfig/ControlConfig.cpp
        Control/ControlConfig/ControlConfig.h Control/ControlConfig/FileConfig.cpp
        Control/ControlConfig/FileConfig.h Control/CommandReader.h Control/ConsoleReader.cpp
        Control/ConsoleReader.h Control/ConsoleSettings.cpp Control/ConsoleSettings.h
        Control/Controller.cpp Control/Controller.h Control/Mediator.cpp Control/Mediator.h
        Control/Settings.cpp Control/Settings.h Events/FieldEvents/Collapse.cpp
        Events/FieldEvents/Collapse.h Events/FieldEvents/Decrease.cpp Events/FieldEvents/Decrease.h
        Events/FieldEvents/FieldEvent.h Events/FieldEvents/Increase.cpp
        Events/FieldEvents/Increase.h Events/GameRulesEvents/Lose.cpp
        Events/GameRulesEvents/Lose.h Events/GameRulesEvents/RulesEvent.h
        Events/GameRulesEvents/Win.cpp Events/GameRulesEvents/Win.h
        Events/PlayerEvents/Enemy.cpp Events/PlayerEvents/Enemy.h
        Events/PlayerEvents/GetCoin.cpp Events/PlayerEvents/GetCoin.h
        Events/PlayerEvents/Heal.cpp Events/PlayerEvents/Heal.h
        Events/PlayerEvents/PlayerEvent.h Events/Event.h
        Events/EventBuilder.cpp Events/EventBuilder.h
        Info/Enums.h Info/LogOutInfo.cpp Info/LogOutInfo.h
        Logging/Logger.cpp Logging/Logger.h Logging/Message.cpp Logging/Message.h
        Logging/Observer.h Logging/Subject.cpp Logging/Subject.h
        Logging/logs/ErrorsObserver.cpp Logging/logs/ErrorsObserver.h
        Logging/logs/GameObserver.cpp Logging/logs/GameObserver.h
        Logging/logs/StatusObserver.cpp Logging/logs/StatusObserver.h
        Output/ConsoleOut.cpp Output/ConsoleOut.h
        Output/FileOut.cpp Output/FileOut.h Output/Output.h
        Background/FieldGeneration/IFieldGenerator.h)
