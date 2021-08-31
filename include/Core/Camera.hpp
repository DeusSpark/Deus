#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Camera
{
    friend class World;

private:
    Camera(const sf::Vector2f& resolution = sf::Vector2f(256.0f, 256.0f));
    ~Camera();

    void handleEvent(sf::Event& event);
    void update(float dt);

public:
    const sf::View&     getView() const;
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getResolution() const;

    float getAspectRation() const;

    void resize(const sf::Vector2f& size);

private:
    sf::View     m_view;
    sf::Vector2f m_resolution;
    sf::Vector2f m_size;

    sf::Vector2f m_position;
    sf::Vector2f m_direction;
    float        m_speed;
};
