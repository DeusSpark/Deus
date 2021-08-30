#pragma once

#include <SFML/Graphics/CircleShape.hpp>

namespace sf
{
class Event;
}

class Window;

class DebugShape
{
public:
    DebugShape();
    ~DebugShape();

    void handleEvent(sf::Event& event);
    void update(float dt);
    void draw(Window& window);

    sf::CircleShape m_shape;
};
