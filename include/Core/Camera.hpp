#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Camera
{
public:
    Camera(const sf::Vector2f& size = sf::Vector2f(256.0f, 256.0f));
    ~Camera();

    void handleEvent(sf::Event& event);
    void update(float dt);

    const sf::View& getView() const;

    void resize(const sf::Vector2f& size);
    void setSpectatorMode(bool isSpectatorMode);

private:
    sf::View     m_view;
    sf::Vector2f m_size;

    sf::Vector2f m_direction;
    float        m_speed;
};
