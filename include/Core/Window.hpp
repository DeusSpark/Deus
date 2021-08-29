#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>

#include <Core/Camera.hpp>

class Window
{
public:
    Window(const sf::Vector2u& size = sf::Vector2u(1024, 720), const std::string& title = "Deus");
    ~Window();

    bool poolEvent(sf::Event& event);
    void draw(const sf::Drawable& object, const sf::RenderStates& states = sf::RenderStates::Default);

    void close();
    void clear();
    void display();

    const sf::RenderWindow& getRenderWindow() const;

    void setCamera(Camera& camera);

private:
    sf::RenderWindow m_renderWindow;
    Camera*          m_camera;
};
