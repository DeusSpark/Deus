#pragma once

namespace sf
{
class Event;
}

class Window;
class World;

class Level
{
public:
    Level();
    virtual ~Level();

    virtual void init()                        = 0;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt)              = 0;
    virtual void draw(Window& window)          = 0;

    void setWorld(World& world);

protected:
    World* m_world;
};
