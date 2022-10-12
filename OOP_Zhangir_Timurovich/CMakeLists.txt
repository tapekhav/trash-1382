cmake_minimum_required(VERSION 3.16)
project(OOP_Zhangir_Timurovich)

set(CMAKE_CXX_STANDARD 14)

include_directories(Background)
include_directories(Characters)
include_directories(Control)
include_directories(Events)
include_directories(CellTypes)

add_executable(OOP_Zhangir_Timurovich
        Background/Cell.cpp
        Background/Cell.h
        Background/CellView.cpp
        Background/CellView.h
        Background/Field.cpp
        Background/Field.h
        Background/FieldView.cpp
        Background/FieldView.h
        Characters/Player.cpp
        Characters/Player.h
        Control/CommandReader.cpp
        Control/CommandReader.h
        Control/Controller.cpp
        Control/Controller.h
        Control/Mediator.cpp
        Control/Mediator.h
        Events/Event.h
        main.cpp CellTypes/CellType.h Characters/PlayerView.cpp Characters/PlayerView.h Events/FieldEvents/FieldEvent.h Events/PlayerEvents/PlayerEvent.h Events/PlayerEvents/GetCoin.cpp Events/PlayerEvents/GetCoin.h Events/PlayerEvents/Heal.cpp Events/PlayerEvents/Heal.h Events/PlayerEvents/Enemy.cpp Events/PlayerEvents/Enemy.h Events/FieldEvents/Collapse.cpp Events/FieldEvents/Collapse.h Events/GameRulesEvents/RulesEvent.h Events/FieldEvents/Increase.cpp Events/FieldEvents/Increase.h Events/FieldEvents/Decrease.cpp Events/FieldEvents/Decrease.h Events/GameRulesEvents/Win.cpp Events/GameRulesEvents/Win.h Events/GameRulesEvents/Lose.cpp Events/GameRulesEvents/Lose.h CellTypes/CoinType.cpp CellTypes/CoinType.h CellTypes/EnemyType.cpp CellTypes/EnemyType.h CellTypes/WallVertType.cpp CellTypes/WallVertType.h CellTypes/WallHorType.cpp CellTypes/WallHorType.h CellTypes/HealType.cpp CellTypes/HealType.h CellTypes/EmptyType.cpp CellTypes/EmptyType.h CellTypes/PlayerType.cpp CellTypes/PlayerType.h CellTypes/StoneType.cpp CellTypes/StoneType.h CellTypes/CollapseType.cpp CellTypes/CollapseType.h CellTypes/IncreaseType.cpp CellTypes/IncreaseType.h CellTypes/DecreaseType.cpp CellTypes/DecreaseType.h)
