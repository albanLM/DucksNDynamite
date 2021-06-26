cmake_minimum_required(VERSION 3.19)
project(DucksNDynamite)

set(CMAKE_CXX_STANDARD 20)

add_executable(DucksNDynamite
        src/Controllers/actions.cpp
        src/Controllers/controller.cpp
        src/Controllers/controllersmanager.cpp
        src/Controllers/keyboardcontroller.cpp
        src/Controllers/windowcontroller.cpp
        src/GameEngine/entitiesmanager.cpp
        src/GameEngine/entity.cpp
        src/GameEngine/hitbox.cpp
        src/GameEngine/tangibleentity.cpp
        src/GraphicalEngine/graphicalobject.cpp
        src/GraphicalEngine/graphicalplan.cpp
        src/GraphicalEngine/graphicalscene.cpp
        src/GraphicalEngine/spritesheet.cpp
        src/GraphicalEngine/window.cpp
        src/game.cpp
        src/main.cpp
        src/rectangle.cpp)

target_include_directories(DucksNDynamite PRIVATE include/)
target_include_directories(DucksNDynamite PRIVATE include/Controllers)
target_include_directories(DucksNDynamite PRIVATE include/GameEngine)
target_include_directories(DucksNDynamite PRIVATE include/GraphicalEngine)

### Dependencies
## Add SDL2
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
target_link_libraries(DucksNDynamite PRIVATE SDL2::Main SDL2::Image)