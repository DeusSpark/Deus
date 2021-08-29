# Minimum CMake version
cmake_minimum_required(VERSION 3.18.4)

# Project name
project(Deus)


# Include directory
set(INCROOT include)

# Source directory
set(SRCROOT src)

# All sources
set(SRC 
    # Main
    ${SRCROOT}/Main.cpp
    ${INCROOT}/Game.hpp
    ${SRCROOT}/Game.cpp
    
    # Debug
    ${INCROOT}/Debug/DebugLevel.hpp
    ${SRCROOT}/Debug/DebugLevel.cpp
    ${INCROOT}/Debug/DebugEntity.hpp
    ${SRCROOT}/Debug/DebugEntity.cpp

    # Levels
    ${INCROOT}/Levels/Level.hpp
    ${SRCROOT}/Levels/Level.cpp
    ${INCROOT}/Levels/GameLevel.hpp
    ${SRCROOT}/Levels/GameLevel.cpp
    ${INCROOT}/Levels/MenuLevel.hpp
    ${SRCROOT}/Levels/MenuLevel.cpp

    # Core
    ${INCROOT}/Core/Window.hpp
    ${SRCROOT}/Core/Window.cpp
    ${INCROOT}/Core/Camera.hpp
    ${SRCROOT}/Core/Camera.cpp
    ${INCROOT}/Core/World.hpp
    ${SRCROOT}/Core/World.cpp

    # World
    ${INCROOT}/World/TileMap.hpp
    ${SRCROOT}/World/TileMap.cpp

    # Entities
    ${INCROOT}/Entities/Entity.hpp
    ${SRCROOT}/Entities/Entity.cpp

    )

# Add executable
add_executable(${PROJECT_NAME} ${SRC})

# Root includes
target_include_directories(${PROJECT_NAME} PRIVATE ${INCROOT})


# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Link SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)
