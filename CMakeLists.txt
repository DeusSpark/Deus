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
    ${SRCROOT}/Main.cpp
    ${INCROOT}/Game.hpp
    ${SRCROOT}/Game.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SRC})

# Root includes
target_include_directories(${PROJECT_NAME} PRIVATE ${INCROOT})


# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Link SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)
