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
    void updateMousePos();

public:
    void draw(const sf::Drawable& object, const sf::RenderStates& states = sf::RenderStates::Default);

    void close();

    const sf::Vector2i& getMousePosScreen() const;
    const sf::Vector2i& getMousePosWindow() const;
    const sf::Vector2f& getMousePosView() const;

    sf::Vector2u getSize() const;

private:
    sf::RenderWindow m_renderWindow;
    sf::Vector2i     m_desktopSize;

    sf::Vector2i m_mousePosScreen;
    sf::Vector2i m_mousePosWindow;
    sf::Vector2f m_mousePosView;

    std::string m_title;

    bool m_isFullscreen;
};
