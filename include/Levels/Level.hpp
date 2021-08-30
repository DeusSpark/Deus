#pragma once

namespace sf
{
class Event;
}

class Window;
class World;
class Camera;

class Level
{
public:
    Level();
    virtual ~Level();

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt)              = 0;
    virtual void draw(Window& window)          = 0;
};
