#pragma once

namespace sf
{
class Event;
}

class Window;

class Entity
{
public:
    Entity();
    virtual ~Entity();

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt)              = 0;

protected:
private:
};
