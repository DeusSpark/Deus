#pragma once

#include <Core/Window.hpp>
#include <Core/World.hpp>

class Game
{
public:
    Game();
    ~Game();

    void run();

    static Window& getWindow();
    static World&  getWorld();

private:
    sf::Clock m_clock;
    sf::Time  m_dt;

    static Window m_window;
    static World  m_world;

    void handleEvent();
    void update();
    void draw();
};