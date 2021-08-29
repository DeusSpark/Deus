#pragma once

#include <Core/Camera.hpp>
#include <Core/Window.hpp>
#include <Core/World.hpp>

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    sf::Clock m_clock;
    sf::Time  m_dt;

    Window m_window;
    Camera m_camera;
    World  m_world;

    void handleEvent();
    void update();
    void draw();
};