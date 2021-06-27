cmake_minimum_required(VERSION 3.19)
project(DucksNDynamite)

set(CMAKE_CXX_STANDARD 20)

add_executable(DucksNDynamite
        src/controllers/actions.cpp
        src/controllers/controller.cpp
        src/controllers/controllers_manager.cpp
        src/controllers/keyboard_controller.cpp
        src/controllers/window_controller.cpp
        src/game_engine/entities_manager.cpp
        src/game_engine/entity.cpp
        src/game_engine/hitbox.cpp
        src/game_engine/tangible_entity.cpp
        src/graphical_engine/graphical_object.cpp
        src/graphical_engine/graphical_plan.cpp
        src/graphical_engine/graphical_scene.cpp
        src/graphical_engine/spritesheet.cpp
        src/graphical_engine/window.cpp
        src/game.cpp
        src/main.cpp
        src/rectangle.cpp src/game_engine/tangible_entities/character.cpp
        include/game_engine/tangible_entities/character.h)

target_include_directories(DucksNDynamite PRIVATE include/)
target_include_directories(DucksNDynamite PRIVATE include/controllers)
target_include_directories(DucksNDynamite PRIVATE include/game_engine)
target_include_directories(DucksNDynamite PRIVATE include/graphical_engine)
target_include_directories(DucksNDynamite PRIVATE include/game_engine/tangible_entities)

### Dependencies
## Add SDL2
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
target_link_libraries(DucksNDynamite PRIVATE SDL2::Main SDL2::Image)