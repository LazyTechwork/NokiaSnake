cmake_minimum_required(VERSION 3.26)
project(NokiaSnake)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(NokiaSnake main.cpp
        src/common/Point2D.cpp
        src/common/Point2D.h
        src/level/Snake.cpp
        src/level/Snake.h
        src/Game.cpp
        src/Game.h
        src/level/Level.cpp
        src/level/Level.h
        src/level/BlockGate.cpp
        src/level/BlockGate.h
        src/common/Direction.h
        src/level/BlockFood.cpp
        src/level/BlockFood.h
        src/level/BlockBorder.cpp
        src/level/BlockBorder.h
        src/level/Block.h
        src/level/Block.cpp
        src/level/LevelLoader.cpp
        src/level/LevelLoader.h
        src/Player.cpp
        src/Player.h
        src/event/BlockEvent.h
        src/event/DealSnakeDamageEvent.cpp
        src/event/DealSnakeDamageEvent.h
        src/event/IncreaseScoreEvent.cpp
        src/event/IncreaseScoreEvent.h
        src/event/TeleportSnake.cpp
        src/event/TeleportSnake.h
        src/contract/LevelContract.cpp
        src/contract/LevelContract.h
        src/contract/MapBlockType.h
        src/model/LevelInfo.h
        src/proxy/ConsoleProxy.cpp
        src/proxy/ConsoleProxy.h
        src/common/InputAction.h
        src/contract/UserSettingsContract.cpp
        src/contract/UserSettingsContract.h
        src/proxy/GameProxy.h
        src/event/LevelPassEvent.cpp
        src/event/LevelPassEvent.h
)

target_link_libraries(NokiaSnake ncursesw pthread)
