#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    sf::RenderWindow m_window;
    sf::Event        m_event;

    void event();
    void update();
    void render();
};