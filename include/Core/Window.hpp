#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>

#include <Core/Camera.hpp>

class Window
{
    friend class Game;

private:
    Window(const sf::Vector2u& size = sf::Vector2u(1024, 720), const std::string& title = "Deus");
    ~Window();

    bool poolEvent(sf::Event& event);

    void clear();
    void display();

public:
    void draw(const sf::Drawable& object, const sf::RenderStates& states = sf::RenderStates::Default);

    void close();

private:
    sf::RenderWindow m_renderWindow;
};
